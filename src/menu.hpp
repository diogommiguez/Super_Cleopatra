#ifndef menu_hpp
#define menu_hpp

#include "ofMain.h"
#include <stdio.h>
#include "slider.hpp"
#include "toggle.hpp"

class menu : public ofBaseApp{
    public:
        menu() {};
    
        vector<toggle> vecToggles;
        vector<slider> vecSliders;
    
        int menu_x = 25;
        int menu_y = 25;
        int menu_width = 270;
        int menu_height = 130;

        bool pop_menu = false;
        bool dragged = false;

        int drag_distx = 0;
        int drag_disty = 0;
};

#endif /* menu_hpp */
