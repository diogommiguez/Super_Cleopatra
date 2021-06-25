#include "ofApp.h"

// FUNÇÕES GERAIS
double distance(double x1, double y1, double x2, double y2)
{
    return pow(pow(x1 - x2, 2) + pow(y1 - y2, 2),1/2.0);
}

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
    //PEGAR NA BOLA
    if (ofGetMousePressed() and (distance(posx, posy, ofGetMouseX(), ofGetMouseY()) < radius or caught))
    {
        posx = ofGetMouseX();
        posy = ofGetMouseY();
        caught = true;
    } else {
      
    caught = false;
    hit_note = false;

    double aux_x = posx;
    double aux_y = posy;

    posx += dt*v_x + dt*dt*a*(ofGetMouseX()-posx)/(0.01+abs(pow(ofGetMouseX()-posx,1)));
    posy += dt*v_y + dt*dt*(g+(ofGetMouseY()-posy)*a/(0.01+abs(pow(ofGetMouseY()-posy,1))));

    v_x= (posx-aux_x)/dt;
    v_y= (posy-aux_y)/dt;
    
    if(posy >ofGetHeight()-radius-15 && closed_floor ){
            hit_note = true;
            posy = ofGetHeight()-radius-15;
            set_v_y(-get_v_y());
            note = posx*5/ofGetWidth()+1;
        }
    // CONDIÇÕES FRONTEIRA
    if(posx > ofGetWidth()){
        posx -= ofGetWidth();
    }
    if(posx < 0){
        posx += ofGetWidth();
    }
      
    }
}

//--------------------------------------------------------------
int Ball::getNote(){
    return note;
}

//--------------------------------------------------------------
void ofApp::setup(){
    attack = 300;
    decay = 1500;
    
    ofSoundStreamSetup(2, 0); // 2 output channels (stereo), 0 input channels
    ofSetCircleResolution(100);
    
}

//--------------------------------------------------------------
void ofApp::audioOut( ofSoundBuffer &outBuffer) {
    float sample;
    for(int i = 0; i < outBuffer.size(); i += 2) {
        sample=0;
        for(int ball=0; ball < N ;ball++)
        {
            sample += sin(balls[ball].getNote()*0.5*(1+ball/2.0)*phase[ball])*envelope(phase[ball]); // generating a sine wave sample
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
    ofColor colorOne(0, 50, 255);
   ofColor colorTwo(50, 0, 100);

   ofBackgroundGradient(colorOne, colorTwo, OF_GRADIENT_CIRCULAR);

    for(int i = 0; i<balls.size(); i++){
        ofSetColor(balls[i].get_color());
        ofDrawCircle(balls[i].get_posx(), balls[i].get_posy(), balls[i].get_radius());
    }
    for(int i =0; i<15; i++){
        ofSetColor(i*255/5, 100*(1+sin(i)), 255-i*255/5);
        ofDrawRectangle(i*ofGetWidth()/5, ofGetHeight()-15, (i+1)*ofGetWidth()/5, ofGetHeight());
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
        case 'b':
            newBall(ofGetMouseX(),ofGetMouseY());
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
