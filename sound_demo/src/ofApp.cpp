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
    hit_note = false;

    double aux_x = posx;
    double aux_y = posy;

    posx += dt*v_x + dt*dt*a*(ofGetMouseX()-posx)/(0.01+abs(pow(ofGetMouseX()-posx,1)));
    posy += dt*v_y + dt*dt*(g+(ofGetMouseY()-posy)*a/(0.01+abs(pow(ofGetMouseY()-posy,1))));

    v_x= (posx-aux_x)/dt;
    v_y= (posy-aux_y)/dt;
    
    if(posy >ofGetHeight()-radius && closed_floor ){
            hit_note = true;
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
void ofApp::setup(){
    attack = 300;
    decay = 1500;
    
    ofSoundStreamSetup(2, 0); // 2 output channels (stereo), 0 input channels
}

//--------------------------------------------------------------
void ofApp::audioOut( ofSoundBuffer &outBuffer) {
    float sample;
    for(int i = 0; i < outBuffer.size(); i += 2) {
        sample=0;
        for(int ball=0; ball < N ;ball++)
        {
            sample += sin(0.5*(1+ball/2.0)*phase[ball])*envelope(phase[ball]); // generating a sine wave sample
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
}

//--------------------------------------------------------------
void ofApp::update(){
    double time = ofGetSystemTimeMillis()/1000.0;
    for(int i = 0; i<balls.size(); i++){
        if(balls[i].hit_note==true){
            phase[i] = 0;
        }
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
        case 'q':
            OF_EXIT_APP(0);
            break;
        case ' ':
            move();
            break;
        case 'o':
            open_floor();
            break;
        case 'a':
            phase[0]=0;
            break;
        case 'b':
            phase[1]=0;
            break;
//        case 'c':
//            phase[2]=0;
//            break;
    }
}

//--------------------------------------------------------------
void ofApp::newBall(int xball, int yball){
    Ball myball;
    myball.set_posx(xball);
    myball.set_posy(yball);
    myball.set_radius(ofRandom(20,30));
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
