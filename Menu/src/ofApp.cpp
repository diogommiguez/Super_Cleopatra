#include "ofApp.h"
//--------------------------------------------------------------//
// TOGGLE                                                       //
//--------------------------------------------------------------//
void toggle::toggle_status(){
    if(status)
        status = false;
    else
        status = true;
}
void toggle::setup(int x, int y)
{
    posx = x;
    posy = y;
}

void toggle::run(){
    ofNoFill();
    ofDrawRectangle(posx, posy, size, size);
    
    ofFill();
    if (not ofGetMousePressed())
        mouse_previous_pressed = false;
    if (ofGetMousePressed() and (not mouse_previous_pressed)){
        mouse_previous_pressed = true;
        if (((abs(ofGetMouseX() - posx - size/2.0) < size/2.0) and abs(ofGetMouseY() - posy - size/2.0) < size/2.0))
        {
            ofDrawRectangle(posx + 3, posy + 3, size - 6, size - 6);
            toggle_status();
        }
    }
    if (status == true){
        ofDrawRectangle(posx + 3, posy + 3, size - 6, size - 6);
    }
}

//--------------------------------------------------------------//
// SLIDER                                                       //
//--------------------------------------------------------------//
int slider::get_posx(){
    return posx;
}

int slider::get_posy(){
    return posy;
}

int slider::get_value(){
    return value;
}

void slider::setup(int x, int y){
    posx = x;
    posy = y;
    
    ticker_y = posy + height - (height/100.0 + 5);
}

void slider::run(){
    ofNoFill();
    ofDrawRectangle(posx, posy, width, height);
    int altura_ticker = height/100 + 5;
    ofDrawRectangle(posx, ticker_y, width, altura_ticker); //Ticker
    
    if (ofGetMousePressed() and ((abs(ofGetMouseX() - posx - width/2.0) < width/2.0 - altura_ticker/2.0) and abs(ofGetMouseY() - posy - height/2.0) < height/2.0 - altura_ticker/2.0))
    {
        //ofFill();
        ticker_y = (int)(ofGetMouseY() - altura_ticker/2.0 + 1);
    }
    value = 102*(100 - 100*(ticker_y - (posy + altura_ticker))/height  - 12)/93;
}

//--------------------------------------------------------------//
// ofApp                                                        //
//--------------------------------------------------------------//
void ofApp::setup(){
    button1.setup(ofGetWindowWidth()/2 - 50, ofGetWindowHeight()/2);
    button2.setup(ofGetWindowWidth()/2, ofGetWindowHeight()/2);
    button3.setup(ofGetWindowWidth()/2 + 50, ofGetWindowHeight()/2);
    
    slider1.setup(ofGetWindowWidth()/2, ofGetWindowHeight()/2 + 200);
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    button1.run();
    button2.run();
    button3.run();
    
    slider1.run();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
