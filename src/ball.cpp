//
//  ball.cpp
//  sound_demo
//
//  Created by Diogo Miguez on 27/06/2021.
//

#include "ball.hpp"


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
            //note = notes[(int)(posx*nnotes/ofGetWidth())];
            note = (int)(posx*nnotes/ofGetWidth());
        }
    // CONDIÇÕES FRONTEIRA
    if(posx > ofGetWidth()){
        posx = ofGetWidth();
        v_x *= -1;
        //posx -= ofGetWidth();
    }
    if(posx < 0){
        posx = 0;
        v_x *= -1;
        //posx += ofGetWidth();
    }
      
    }
}

//--------------------------------------------------------------
int Ball::getNote(){
    return note;
}
