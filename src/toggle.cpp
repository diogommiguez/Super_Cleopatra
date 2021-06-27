//
//  toggle.cpp
//  sound_demo
//
//  Created by Diogo Miguez on 27/06/2021.
//

#include "toggle.hpp"

toggle::toggle(int x, int y)
{
    posx = x;
    posy = y;
}

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
