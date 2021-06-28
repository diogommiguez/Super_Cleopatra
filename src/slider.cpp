//
//  slider.cpp
//  sound_demo
//
//  Created by Diogo Miguez on 27/06/2021.
//

#include "slider.hpp"

slider::slider(int x, int y){
    posx = x;
    posy = y;
    
    ticker_y = posy + height - (height/100.0 + 5);
}

int slider::get_posx(){
    return posx;
}

int slider::get_posy(){
    return posy;
}

int slider::get_value(){
    return value;
}

void slider::update(int x, int y){
    ticker_y -= posy - y;

    posx = x;
    posy = y;
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

    //
    if (ofGetMousePressed() and ((abs(ofGetMouseX() - posx - width/2.0) < width/2.0) and abs(ofGetMouseY() - posy - height/2.0) < height/2.0 - altura_ticker/2.0))
    {
        //ofFill();
        ticker_y = (int)(ofGetMouseY() - altura_ticker/2.0 + 1);
    }
    value = 102*(100 - 100*(ticker_y - (posy + altura_ticker))/height  - 12)/93;
    ofFill();
    ofDrawRectangle(posx, ticker_y+altura_ticker, width, height -(ticker_y-posy+altura_ticker)); //Ticker
}
