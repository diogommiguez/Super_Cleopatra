//
//  toggle.hpp
//  sound_demo
//
//  Created by Diogo Miguez on 27/06/2021.
//

#ifndef toggle_hpp
#define toggle_hpp

#include "ofMain.h"
#include <stdio.h>

class toggle : public ofBaseApp{
    private:
        int  posx;
        int  posy;
        bool status = false; //On (True) - Off (False)
        int  size = 20;
        bool mouse_previous_pressed;
    public:
        toggle(int,int);
        void setup(int, int);
        void run();
    
        int get_posx();
        int get_posy();
        bool get_status();
    
        void toggle_status();
};

#endif /* toggle_hpp */
