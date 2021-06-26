#include "ofApp.h"

// FUNÇÕES GERAIS
double distance(double x1, double y1, double x2, double y2)
{
    return pow(pow(x1 - x2, 2) + pow(y1 - y2, 2),1/2.0);
}

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
            cout << "toggle x: " << posx << "\nrato x: " << ofGetMouseX() << endl;
            cout << "toggle y: " << posy << "\nrato y: " << ofGetMouseY() << endl;
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
    ofFill();
}

//--------------------------------------------------------------//
// BALL                                                         //
//--------------------------------------------------------------//

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
        double aux_x = posx;
        double aux_y = posy;
        
        posx = ofGetMouseX();
        posy = ofGetMouseY();
        
        v_x= (posx-aux_x)/dt;
        v_y= (posy-aux_y)/dt;
        
        caught = true;
    } else {
      
    caught = false;
    hit_note = false;

    double aux_x = posx;
    double aux_y = posy;

    int gravity = (mouse_g==true)? 1 : 0 ;
        
    posx += dt*v_x + gravity*dt*dt*a*(ofGetMouseX()-posx)/(0.01+abs(pow(ofGetMouseX()-posx,1)));
    posy += dt*v_y + dt*dt*(g+gravity*(ofGetMouseY()-posy)*a/(0.01+abs(pow(ofGetMouseY()-posy,1))));

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

//--------------------------------------------------------------//
// ofApp                                                        //
//--------------------------------------------------------------//

//--------------------------------------------------------------
void ofApp::setup(){
    attack = 100;
    decay = 100;
    
    ofSoundStreamSetup(2, 0); // 2 output channels (stereo), 0 input channels
    ofSetCircleResolution(100);
    
    mech_menu.menu_x = synth_menu.menu_x;
    mech_menu.menu_y = synth_menu.menu_y + synth_menu.menu_height + 20;
    
    synth_menu.button1.setup(synth_menu.menu_x+synth_menu.menu_width/8.0,synth_menu.menu_y+synth_menu.menu_height/2.0);
    synth_menu.button2.setup(synth_menu.menu_x+2*synth_menu.menu_width/8.0,synth_menu.menu_y+synth_menu.menu_height/2.0);
    synth_menu.button3.setup(synth_menu.menu_x+3*synth_menu.menu_width/8.0,synth_menu.menu_y+synth_menu.menu_height/2.0);
   
    synth_menu.slider1.setup(synth_menu.menu_x+4*synth_menu.menu_width/8.0,synth_menu.menu_y+25);
    synth_menu.slider2.setup(synth_menu.menu_x+5*synth_menu.menu_width/8.0,synth_menu.menu_y+25);
    synth_menu.slider3.setup(synth_menu.menu_x+6*synth_menu.menu_width/8.0,synth_menu.menu_y+25);
    synth_menu.slider4.setup(synth_menu.menu_x+7*synth_menu.menu_width/8.0,synth_menu.menu_y+25);

    mech_menu.button1.setup(mech_menu.menu_x+mech_menu.menu_width/7.0,mech_menu.menu_y+mech_menu.menu_height/2.0);
    mech_menu.button2.setup(mech_menu.menu_x+2*mech_menu.menu_width/7.0,mech_menu.menu_y+mech_menu.menu_height/2.0);
    mech_menu.button3.setup(mech_menu.menu_x+3*mech_menu.menu_width/7.0,mech_menu.menu_y+mech_menu.menu_height/2.0);
   
    mech_menu.slider1.setup(mech_menu.menu_x+4*mech_menu.menu_width/7.0,mech_menu.menu_y+25);
    mech_menu.slider2.setup(mech_menu.menu_x+5*mech_menu.menu_width/7.0,mech_menu.menu_y+25);
    mech_menu.slider3.setup(mech_menu.menu_x+6*mech_menu.menu_width/7.0,mech_menu.menu_y+25);
    
}

//--------------------------------------------------------------
void ofApp::audioOut( ofSoundBuffer &outBuffer) {
    float sample;
    for(int i = 0; i < outBuffer.size(); i += 2) {
        sample=0;
        for(int ball=0; ball < N ;ball++)
        {
            sample += sin(balls[ball].getNote()*phase[ball])*envelope(phase[ball]); // generating a sine wave sample
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
void ofApp::update(){

    for(int i = 0; i<balls.size() and !pause; i++){
        if(balls[i].hit_note==true){
            phase[i] = 0;
        }
        balls[i].evolve();
    }
    synth_menu.button1.setup(synth_menu.menu_x+synth_menu.menu_width/8.0,synth_menu.menu_y+synth_menu.menu_height/2.0);
    synth_menu.button2.setup(synth_menu.menu_x+2*synth_menu.menu_width/8.0,synth_menu.menu_y+synth_menu.menu_height/2.0);
    synth_menu.button3.setup(synth_menu.menu_x+3*synth_menu.menu_width/8.0,synth_menu.menu_y+synth_menu.menu_height/2.0);
   
    synth_menu.slider1.setup(synth_menu.menu_x+4*synth_menu.menu_width/8.0,synth_menu.menu_y+25);
    synth_menu.slider2.setup(synth_menu.menu_x+5*synth_menu.menu_width/8.0,synth_menu.menu_y+25);
    synth_menu.slider3.setup(synth_menu.menu_x+6*synth_menu.menu_width/8.0,synth_menu.menu_y+25);
    synth_menu.slider4.setup(synth_menu.menu_x+7*synth_menu.menu_width/8.0,synth_menu.menu_y+25);

    mech_menu.button1.setup(mech_menu.menu_x+mech_menu.menu_width/7.0,mech_menu.menu_y+mech_menu.menu_height/2.0);
    mech_menu.button2.setup(mech_menu.menu_x+2*mech_menu.menu_width/7.0,mech_menu.menu_y+mech_menu.menu_height/2.0);
    mech_menu.button3.setup(mech_menu.menu_x+3*mech_menu.menu_width/7.0,mech_menu.menu_y+mech_menu.menu_height/2.0);
   
    mech_menu.slider1.setup(mech_menu.menu_x+4*mech_menu.menu_width/7.0,mech_menu.menu_y+25);
    mech_menu.slider2.setup(mech_menu.menu_x+5*mech_menu.menu_width/7.0,mech_menu.menu_y+25);
    mech_menu.slider3.setup(mech_menu.menu_x+6*mech_menu.menu_width/7.0,mech_menu.menu_y+25);
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
        ofSetColor(100,100,100);
        ofDrawRectangle(synth_menu.menu_x-5, synth_menu.menu_y-5, synth_menu.menu_width+10, synth_menu.menu_height+10);
        ofSetColor(150,150,150);
        ofDrawRectangle(synth_menu.menu_x, synth_menu.menu_y, synth_menu.menu_width, synth_menu.menu_height);
        ofSetColor(150,0,255);
        ofDrawRectangle(synth_menu.menu_x, synth_menu.menu_y, synth_menu.menu_width, 5);
        
        ofSetColor(0,0,255);
        // in draw:
        ofDrawBitmapString("SYNTH MENU", synth_menu.menu_x+synth_menu.menu_width/2.0-105,synth_menu.menu_y+synth_menu.menu_height/6.0);
        
        synth_menu.button1.run();
        synth_menu.button2.run();
        synth_menu.button3.run();
        synth_menu.slider1.run();
        synth_menu.slider2.run();
        synth_menu.slider3.run();
        synth_menu.slider4.run();
    }
    
    if(mech_menu.pop_menu){
        ofSetColor(100,100,100);
        ofDrawRectangle(mech_menu.menu_x-5, mech_menu.menu_y-5, mech_menu.menu_width+10, mech_menu.menu_height+10);
        ofSetColor(150,150,150);
        ofDrawRectangle(mech_menu.menu_x, mech_menu.menu_y, mech_menu.menu_width, mech_menu.menu_height);
        ofSetColor(150,0,255);
        ofDrawRectangle(synth_menu.menu_x, synth_menu.menu_y, synth_menu.menu_width, 5);
        
        ofSetColor(0,0,255);
        // in draw:
        ofDrawBitmapString("MECHANICS MENU", mech_menu.menu_x+mech_menu.menu_width/2.0-100,mech_menu.menu_y+mech_menu.menu_height/6.0);
        
        mech_menu.button1.run();
        mech_menu.button2.run();
        mech_menu.button3.run();
        mech_menu.slider1.run();
        mech_menu.slider2.run();
        mech_menu.slider3.run();
    }
}

//--------------------------------------------------------------
void ofApp::random_v(){
    for(int i = 0; i<balls.size(); i++){
        balls[i].set_v_x(ofRandom(-1000,1000));
        balls[i].set_v_y(ofRandom(-3000,0));
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
        case 'p':
            (pause == false) ? pause = true : pause = false;
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
    if(synth_menu.pop_menu and (x>synth_menu.menu_x and x<synth_menu.menu_x+synth_menu.menu_width and y>synth_menu.menu_y and y<synth_menu.menu_y+10 or synth_menu.dragged)){
        synth_menu.menu_x = ofGetMouseX()-synth_menu.drag_distx;
        synth_menu.menu_y = ofGetMouseY()-synth_menu.drag_disty;
    } else if(mech_menu.pop_menu and (x>mech_menu.menu_x and x<mech_menu.menu_x+mech_menu.menu_width and y>mech_menu.menu_y and y<mech_menu.menu_y+10 or mech_menu.dragged)){
        mech_menu.menu_x = ofGetMouseX()-mech_menu.drag_distx;
        mech_menu.menu_y = ofGetMouseY()-mech_menu.drag_disty;
    }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    if(synth_menu.pop_menu and x>synth_menu.menu_x and x<synth_menu.menu_x+synth_menu.menu_width and y>synth_menu.menu_y and y<synth_menu.menu_y+10){
        synth_menu.drag_distx = ofGetMouseX()-synth_menu.menu_x;
        synth_menu.drag_disty = ofGetMouseY()-synth_menu.menu_y;
        synth_menu.dragged = true;
    } else if(mech_menu.pop_menu and x>mech_menu.menu_x and x<mech_menu.menu_x+mech_menu.menu_width and y>mech_menu.menu_y and y<mech_menu.menu_y+10){
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
