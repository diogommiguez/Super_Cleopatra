#ifndef slider_hpp
#define slider_hpp

#include "ofMain.h"
#include <stdio.h>

class slider : public ofBaseApp{
    private:
        int  posx;
        int  posy;
        int ticker_y;
        int  height = 100;
        int  width  = 20;
        int  value = 0; // 0-100
        bool selected; // Para continuar selecionado quando saimos das fronteiras do slider
    public:
        slider(int,int);
        void setup(int, int);
        void update(int, int);
        void run();

        int get_posx();
        int get_posy();
        int get_value();
    
        bool is_selected();
};

#endif /* slider_hpp */
