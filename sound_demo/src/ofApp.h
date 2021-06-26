/*
 Project Title:
 Description:
 Author: Diogo Miguez
 2021
*/

#include "ofMain.h"

double distance(double x1, double y1, double x2, double y2);

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
        void update(int, int);
        void run();

        int get_posx();
        int get_posy();
        int get_value();
    
        bool is_selected();
};

class Ball : public ofBaseApp{
        double posx;
        double posy;
        int radius;
        ofColor color;
        double g = 5000;
        double a = 1000;
        double v_y = 0;
        double v_x = 0;
        int SAMPLE_RATE = 100;
        double dt = 1.0/SAMPLE_RATE;
        bool closed_floor = true;
        int note=1;
        bool caught = false;
        bool mouse_g = false;
    public:
        void set_posx(double);
        void move_x(double);
        void set_posy(double);
        void move_y(double);
        void set_radius(int);
        void set_color(int);
        void set_v_y(double);
        void set_v_x(double);
        const double get_posx();
        const double get_posy();
        const int get_radius();
        const ofColor get_color();
        const double get_v_y();
        void evolve();
        void set_closed_floor(bool val) {closed_floor = val;};
        int getNote();
        bool hit_note = false;
        void setmouse_g(bool act) {mouse_g = act;};
        bool getmouse_g() {return mouse_g;};
};

class menu : public ofBaseApp{
    public:
        menu() {};
    
        toggle button1;
        toggle button2;
        toggle button3;

        slider slider1;
        slider slider2;
        slider slider3;
    
        slider slider4;
    
        int menu_x = 25;
        int menu_y = 25;
        int menu_width = 270;
        int menu_height = 130;

        bool pop_menu = false;
        bool dragged = false;

        int drag_distx = 0;
        int drag_disty = 0;
};

class ofApp : public ofBaseApp{
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
    //balls
        void newBall(int, int);
        void random_v();
        vector <Ball> balls;
        void open_floor();
        bool pause;
    //audio
        void audioOut(ofSoundBuffer& );
        double envelope(double);
        vector<double> phase;
        double attack;
        double decay;
        double volume = 0.5;
        int N;
    //MENUS
        menu synth_menu;
        menu mech_menu;
};

