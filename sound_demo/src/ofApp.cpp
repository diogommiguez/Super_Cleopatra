#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    attack = 150;
    decay = 200;
    
    ofSoundStreamSetup(2, 0); // 2 output channels (stereo), 0 input channels
    ofSetCircleResolution(100);
    
    // SYNTH MENU ---------------------------------------------

    synth_menu.menu_width = 300;
    synth_menu.menu_height = 210;

    synth_menu.vecToggles.push_back(toggle(synth_menu.menu_x+0*synth_menu.menu_width/8.0+15  ,synth_menu.menu_y+synth_menu.menu_height/3.-30));
    synth_menu.vecToggles.push_back(toggle(synth_menu.menu_x+1*synth_menu.menu_width/8.0+15,synth_menu.menu_y+synth_menu.menu_height/3.-30));
    synth_menu.vecToggles.push_back(toggle(synth_menu.menu_x+2*synth_menu.menu_width/8.0+15,synth_menu.menu_y+synth_menu.menu_height/3.-30));
    
    synth_menu.vecSliders.push_back(slider(synth_menu.menu_x+0*synth_menu.menu_width/8.0+15,synth_menu.menu_y+synth_menu.menu_height/3.));
    synth_menu.vecSliders.push_back(slider(synth_menu.menu_x+1*synth_menu.menu_width/8.0+15,synth_menu.menu_y+synth_menu.menu_height/3.));
    synth_menu.vecSliders.push_back(slider(synth_menu.menu_x+2*synth_menu.menu_width/8.0+15,synth_menu.menu_y+synth_menu.menu_height/3.));
    synth_menu.vecSliders.push_back(slider(synth_menu.menu_x+4*synth_menu.menu_width/8.0,synth_menu.menu_y+synth_menu.menu_height/3.));
    synth_menu.vecSliders.push_back(slider(synth_menu.menu_x+5*synth_menu.menu_width/8.0,synth_menu.menu_y+synth_menu.menu_height/3.));
    synth_menu.vecSliders.push_back(slider(synth_menu.menu_x+6*synth_menu.menu_width/8.0,synth_menu.menu_y+synth_menu.menu_height/3.));
    synth_menu.vecSliders.push_back(slider(synth_menu.menu_x+7*synth_menu.menu_width/8.0,synth_menu.menu_y+synth_menu.menu_height/3.));
    

    // MECHANICS MENU ---------------------------------------------
    
    // pos inicial em relação ao synth menu
    mech_menu.menu_x = synth_menu.menu_x;
    mech_menu.menu_y = synth_menu.menu_y + synth_menu.menu_height + 20;
    
//    mech_menu.button1.setup(mech_menu.menu_x+mech_menu.menu_width/7.0,mech_menu.menu_y+mech_menu.menu_height/2.0);
//    mech_menu.button2.setup(mech_menu.menu_x+2*mech_menu.menu_width/7.0,mech_menu.menu_y+mech_menu.menu_height/2.0);
//    mech_menu.button3.setup(mech_menu.menu_x+3*mech_menu.menu_width/7.0,mech_menu.menu_y+mech_menu.menu_height/2.0);
//
//    mech_menu.slider1.setup(mech_menu.menu_x+4*mech_menu.menu_width/7.0,mech_menu.menu_y+25);
//    mech_menu.slider2.setup(mech_menu.menu_x+5*mech_menu.menu_width/7.0,mech_menu.menu_y+25);
//    mech_menu.slider3.setup(mech_menu.menu_x+6*mech_menu.menu_width/7.0,mech_menu.menu_y+25);
    
}

//--------------------------------------------------------------
void ofApp::update(){

    for(int i = 0; i<balls.size() and !pause; i++){
        if(balls[i].hit_note==true){
            phase[i] = 0;
        }
        balls[i].evolve();
    }
    synth_menu.vecToggles[0].setup(synth_menu.menu_x+0*synth_menu.menu_width/8.0+15,synth_menu.menu_y+synth_menu.menu_height/3.-30);
    synth_menu.vecToggles[1].setup(synth_menu.menu_x+1*synth_menu.menu_width/8.0+15,synth_menu.menu_y+synth_menu.menu_height/3.-30);
    synth_menu.vecToggles[2].setup(synth_menu.menu_x+2*synth_menu.menu_width/8.0+15,synth_menu.menu_y+synth_menu.menu_height/3.-30);

    synth_menu.vecSliders[0].update(synth_menu.menu_x+0*synth_menu.menu_width/8.0+15,synth_menu.menu_y+synth_menu.menu_height/3.);
    synth_menu.vecSliders[1].update(synth_menu.menu_x+1*synth_menu.menu_width/8.0+15,synth_menu.menu_y+synth_menu.menu_height/3.);
    synth_menu.vecSliders[2].update(synth_menu.menu_x+2*synth_menu.menu_width/8.0+15,synth_menu.menu_y+synth_menu.menu_height/3.);
    synth_menu.vecSliders[3].update(synth_menu.menu_x+4*synth_menu.menu_width/8.0,synth_menu.menu_y+synth_menu.menu_height/3.);
    synth_menu.vecSliders[4].update(synth_menu.menu_x+5*synth_menu.menu_width/8.0,synth_menu.menu_y+synth_menu.menu_height/3.);
    synth_menu.vecSliders[5].update(synth_menu.menu_x+6*synth_menu.menu_width/8.0,synth_menu.menu_y+synth_menu.menu_height/3.);
    synth_menu.vecSliders[6].update(synth_menu.menu_x+7*synth_menu.menu_width/8.0,synth_menu.menu_y+synth_menu.menu_height/3.);
    
    
//    mech_menu.button1.setup(mech_menu.menu_x+mech_menu.menu_width/7.0,mech_menu.menu_y+mech_menu.menu_height/2.0);
//    mech_menu.button2.setup(mech_menu.menu_x+2*mech_menu.menu_width/7.0,mech_menu.menu_y+mech_menu.menu_height/2.0);
//    mech_menu.button3.setup(mech_menu.menu_x+3*mech_menu.menu_width/7.0,mech_menu.menu_y+mech_menu.menu_height/2.0);
//
//    mech_menu.slider1.update(mech_menu.menu_x+4*mech_menu.menu_width/7.0,mech_menu.menu_y+25);
//    mech_menu.slider2.update(mech_menu.menu_x+5*mech_menu.menu_width/7.0,mech_menu.menu_y+25);
//    mech_menu.slider3.update(mech_menu.menu_x+6*mech_menu.menu_width/7.0,mech_menu.menu_y+25);
    
    attack = synth_menu.vecSliders[3].get_value()*10.0+1;
    decay = synth_menu.vecSliders[4].get_value()*10.0+1;
    volume = synth_menu.vecSliders[6].get_value()/200.0;
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofColor colorOne(50, 25,200);
    ofColor colorTwo(150, 20, 150);

    ofBackgroundGradient(colorOne, colorTwo, OF_GRADIENT_LINEAR);

    for(int i = 0; i<balls.size(); i++){
        ofSetColor(balls[i].get_color());
        ofDrawCircle(balls[i].get_posx(), balls[i].get_posy(), balls[i].get_radius());
    }
    for(int i =0; i<15; i++){
        ofSetColor(i*255/5, 100*(1+sin(i)), 255-i*255/5);
        ofDrawRectangle(i*ofGetWidth()/5, ofGetHeight()-15, (i+1)*ofGetWidth()/5, ofGetHeight());
    }
    if(synth_menu.pop_menu){
        // CAIXINHAS DE MENU
        ofSetColor(100,100,100);
        ofDrawRectangle(synth_menu.menu_x-5, synth_menu.menu_y-5, synth_menu.menu_width+10, synth_menu.menu_height+10);
        ofSetColor(150,150,150);
        ofDrawRectangle(synth_menu.menu_x, synth_menu.menu_y, synth_menu.menu_width, synth_menu.menu_height);
        ofSetColor(100,100,100);
        ofDrawRectangle(synth_menu.menu_x+3*synth_menu.menu_width/8.0+15, synth_menu.menu_y-5, 5, synth_menu.menu_height+10);
        
        // LETRAS E SIMBOLOS
        ofSetColor(0,0,0);
        ofDrawBitmapString("SYNTH MENU", synth_menu.menu_x+5*synth_menu.menu_width/8.0-10,synth_menu.menu_y+synth_menu.menu_height/8.0);
        
        ofDrawCircle(synth_menu.menu_x+0*synth_menu.menu_width/8.0+25,synth_menu.menu_y+synth_menu.menu_height/3.-50, 10);
        ofDrawRectangle(synth_menu.menu_x+1*synth_menu.menu_width/8.0+15,synth_menu.menu_y+synth_menu.menu_height/3.-60, 20,20);
        ofDrawTriangle(synth_menu.menu_x+2*synth_menu.menu_width/8.0+15,synth_menu.menu_y+synth_menu.menu_height/3.-60,
                       synth_menu.menu_x+2*synth_menu.menu_width/8.0+35,synth_menu.menu_y+synth_menu.menu_height/3.-60,
                       synth_menu.menu_x+2*synth_menu.menu_width/8.0+25,synth_menu.menu_y+synth_menu.menu_height/3.-40);
        
        
        ofSetColor(0,0,255);
        ofDrawBitmapString("ATT", synth_menu.menu_x+4*synth_menu.menu_width/8.0,synth_menu.menu_y+synth_menu.menu_height/3.-20);
        ofDrawBitmapString("DEC",  synth_menu.menu_x+5*synth_menu.menu_width/8.0,synth_menu.menu_y+synth_menu.menu_height/3.-20);
        ofDrawBitmapString("FIL", synth_menu.menu_x+6*synth_menu.menu_width/8.0,synth_menu.menu_y+synth_menu.menu_height/3.-20);
        ofDrawBitmapString("VOL", synth_menu.menu_x+7*synth_menu.menu_width/8.0,synth_menu.menu_y+synth_menu.menu_height/3.-20);
        
        // TOGGLES E SLIDERS
        for(int i =0; i<synth_menu.vecToggles.size(); i++){
            synth_menu.vecToggles[i].run();
        }
        for(int i =0; i<synth_menu.vecSliders.size(); i++){
            synth_menu.vecSliders[i].run();
        }
    }
    
    if(mech_menu.pop_menu){
        ofSetColor(100,100,100);
        ofDrawRectangle(mech_menu.menu_x-5, mech_menu.menu_y-5, mech_menu.menu_width+10, mech_menu.menu_height+10);
        ofSetColor(150,150,150);
        ofDrawRectangle(mech_menu.menu_x, mech_menu.menu_y, mech_menu.menu_width, mech_menu.menu_height);
        
        ofSetColor(0,0,255);
        // in draw:
        ofDrawBitmapString("MECHANICS MENU", mech_menu.menu_x+mech_menu.menu_width/2.0-100,mech_menu.menu_y+mech_menu.menu_height/6.0);
        
//        mech_menu.button1.run();
//        mech_menu.button2.run();
//        mech_menu.button3.run();
//        mech_menu.slider1.run();
//        mech_menu.slider2.run();
//        mech_menu.slider3.run();
    }
}


//--------------------------------------------------------------
void ofApp::audioOut( ofSoundBuffer &outBuffer) {
    float sample;
    for(int i = 0; i < outBuffer.size(); i += 2) {
        sample=0;
        for(int ball=0; ball < N ;ball++)
        {
            sample += volume*( sin(balls[ball].getNote()*phase[ball]/512.0)
                              +0.6*sin(balls[ball].getNote()*3*phase[ball]/512.0)
                              +0.4*sin(balls[ball].getNote()*5*phase[ball]/512.0)
                              +0.2*sin(balls[ball].getNote()*7*phase[ball]/512.0)
                              )*envelope(phase[ball]); // generating a sine wave sample
            phase[ball] += 0.05;
        }
        //float sample = sin(phase[0]);//*envelope(phase[0]); // generating a sine wave sample
            outBuffer[i] = sample; // writing to the left channel
            outBuffer[i + 1] = sample; // writing to the right channel
    }
}

//--------------------------------------------------------------
double ofApp::envelope(double phase){
    if(phase <= attack)
        return phase/attack;
    else if(phase < attack+decay)
        return (attack-phase)/decay + 1;
    else if(phase >= attack+decay)
        return 0;
    return 0;
}

//--------------------------------------------------------------
void ofApp::random_v(){
    for(int i = 0; i<balls.size(); i++){
        balls[i].set_v_x(ofRandom(-1000,1000));
        balls[i].set_v_y(ofRandom(-2000,0));
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
        case 'q':
            OF_EXIT_APP(0);
            break;
        case 'v':
            random_v();
            break;
        case 'o':
            open_floor();
            break;
        case 'b':
            newBall(ofGetMouseX(),ofGetMouseY());
            break;
        case 'g':
            for(int i =0; i<balls.size(); i++){
                (balls[i].getmouse_g() == false) ? balls[i].setmouse_g(true) : balls[i].setmouse_g(false);
            }
            break;
        case 'm':
            (synth_menu.pop_menu == false) ? synth_menu.pop_menu = true : synth_menu.pop_menu = false;
            break;
        case 'n':
            (mech_menu.pop_menu == false) ? mech_menu.pop_menu = true : mech_menu.pop_menu = false;
            break;
        case ' ':
            (pause == false) ? pause = true : pause = false;
            break;
    }
}

//--------------------------------------------------------------
void ofApp::newBall(int xball, int yball){
    Ball myball;
    myball.set_posx(xball);
    myball.set_posy(yball);
    myball.set_radius(ofRandom(30,40));
    myball.set_color(ofRandom(0,255));
    
    balls.push_back(myball);
    N ++;
    phase.push_back(attack+decay);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    if(synth_menu.pop_menu and synth_menu.dragged){
        synth_menu.menu_x = ofGetMouseX()-synth_menu.drag_distx;
        synth_menu.menu_y = ofGetMouseY()-synth_menu.drag_disty;
    } else if(mech_menu.pop_menu and mech_menu.dragged){
        mech_menu.menu_x = ofGetMouseX()-mech_menu.drag_distx;
        mech_menu.menu_y = ofGetMouseY()-mech_menu.drag_disty;
    }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    if(synth_menu.pop_menu and x>synth_menu.menu_x and x<synth_menu.menu_x+synth_menu.menu_width and y>synth_menu.menu_y and y<synth_menu.menu_y+25){
        synth_menu.drag_distx = ofGetMouseX()-synth_menu.menu_x;
        synth_menu.drag_disty = ofGetMouseY()-synth_menu.menu_y;
        synth_menu.dragged = true;
    } else if(mech_menu.pop_menu and x>mech_menu.menu_x and x<mech_menu.menu_x+mech_menu.menu_width and y>mech_menu.menu_y and y<mech_menu.menu_y+25){
        mech_menu.drag_distx = ofGetMouseX()-mech_menu.menu_x;
        mech_menu.drag_disty = ofGetMouseY()-mech_menu.menu_y;
        mech_menu.dragged = true;
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    synth_menu.dragged = false;
    mech_menu.dragged = false;
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
