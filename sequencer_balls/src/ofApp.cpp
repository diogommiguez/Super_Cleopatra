#include "ofApp.h"

//--------------------------------------------------------------
void Ball::set_posx(double x){
    posx = x;
}

//--------------------------------------------------------------
void Ball::move_x(double dx){
    posx += dx;
}

//--------------------------------------------------------------
void Ball::set_posy(double y){
    posy = y;
}

//--------------------------------------------------------------
void Ball::move_y(double dy){
    posy += dy;
}

//--------------------------------------------------------------
void Ball::set_radius(int r){
    radius = r;
}

//--------------------------------------------------------------
void Ball::set_color(int hue){
    color.setHsb(hue, 255, 255);
}

//--------------------------------------------------------------
const double Ball::get_posx(){
    return posx;
}

//--------------------------------------------------------------
const double Ball::get_posy(){
    return posy;
}

//--------------------------------------------------------------
const int Ball::get_radius(){
    return radius;
}

//--------------------------------------------------------------
const double Ball::get_v_y(){
    return v_y;
}

//--------------------------------------------------------------
void Ball::set_v_y(double _v_y){
    v_y = _v_y;
}

//--------------------------------------------------------------
void Ball::set_v_x(double _v_x){
    v_x = _v_x;
}

//--------------------------------------------------------------
const ofColor Ball::get_color(){
    return color;
}

//--------------------------------------------------------------
void Ball::evolve(){
    double aux_x = posx;
    double aux_y = posy;

    posx += dt*v_x + dt*dt*a*(ofGetMouseX()-posx)/(0.01+abs(pow(ofGetMouseX()-posx,1)));
    posy += dt*v_y + dt*dt*(g+(ofGetMouseY()-posy)*a/(0.01+abs(pow(ofGetMouseY()-posy,1))));

    v_x= (posx-aux_x)/dt;
    v_y= (posy-aux_y)/dt;
    
    if(posy >ofGetHeight()-radius && closed_floor ){
            posy = ofGetHeight()-radius;
            set_v_y(-get_v_y());
            getNote(get_posx());
        }

}

//--------------------------------------------------------------
void Ball::getNote(double xpos){
    int note = xpos*5/ofGetWidth()+1;
    cout << "\n" << note << endl;
}

//--------------------------------------------------------------
//--------------------------------------------------------------


//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(SAMPLE_RATE);
}

//--------------------------------------------------------------
void ofApp::update(){
    double time = ofGetSystemTimeMillis()/1000.0;
    for(int i = 0; i<balls.size(); i++){
        balls[i].evolve();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for(int i = 0; i<balls.size(); i++){
        ofSetColor(balls[i].get_color());
        ofDrawCircle(balls[i].get_posx(), balls[i].get_posy(), balls[i].get_radius());
    }
}

//--------------------------------------------------------------
void ofApp::move(){
    for(int i = 0; i<balls.size(); i++){
        balls[i].set_v_x(2000);
    }
}

//--------------------------------------------------------------
void ofApp::open_floor(){
    for(int i = 0; i<balls.size(); i++){
        balls[i].set_closed_floor(false);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch(key) {
        case 'f':
            ofToggleFullscreen();
            break;
        case ' ':
            move();
            break;
        case 'o':
            open_floor();
            break;
    }
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
void ofApp::newBall(int xball, int yball){
    Ball myball;
    myball.set_posx(xball);
    myball.set_posy(yball);
    myball.set_radius(ofRandom(20,30));
    myball.set_color(ofRandom(0,255));
    
    balls.push_back(myball);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    newBall(ofGetMouseX(),ofGetMouseY());
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
