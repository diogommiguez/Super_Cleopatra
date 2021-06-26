#pragma once

#include "ofMain.h"

class toggle : public ofBaseApp{
    private:
        int  posx;
        int  posy;
        bool status = false; //On (True) - Off (False)
        int  size = 20;
        bool mouse_previous_pressed;
    public:
        void setup(int, int);
        void run();
    
        int get_posx();
        int get_posy();
        bool get_status();
    
        void toggle_status();
};

class slider : public ofBaseApp{
    private:
        int  posx;
        int  posy;
        int ticker_y;
        int  height = 100;
        int  width  = 20;
        int  value; // 0-100
        bool selected; // Para continuar selecionado quando saimos das fronteiras do slider
    public:
        void setup(int, int);
        void run();

        int get_posx();
        int get_posy();
        int get_value();
    
        bool is_selected();
};


class ofApp : public ofBaseApp{
    private:
        toggle button1;
        toggle button2;
        toggle button3;
    
        slider slider1;
	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
};
