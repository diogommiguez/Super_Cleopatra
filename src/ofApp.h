/*
 Project Title:
 Description:
 Author: Diogo Miguez
 2021
*/

#include "ofMain.h"
#include "menu.hpp"
#include "ball.hpp"
#include "func.hpp"
#include "ofxmaxim.h"

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
    
        ofTrueTypeFont font;
        ofTrueTypeFont font_bold;
        ofTrueTypeFont font_help_menu;
    //balls
        void newBall(int, int);
        void random_v();
        vector <Ball> balls;
        void floor(bool);
        bool pause;
        bool _floor = true;
        bool _walls = true;
        bool _g = false;
        void close_walls();
    //audio
        void audioOut(ofSoundBuffer& );
        double envelope(double);
        vector<double> phase;
        double attack;
        double decay;
        double volume = 0.5;
        vector<double> notes;
        int note_sel = 1;  
        void setNotes(int);
        double Filterfreq;
        double Resonance;
    
        ofxMaxiFilter myFilter;
        bool* wvforms = new bool[3]; // SINE - SQUARE - TRIANGLE
        
        ofSoundStream soundstream;
        
    //MENUS
        menu synth_menu ;
        menu help_menu ;
        menu stats_menu ; // Nballs, escala, gravidade, walls, floor

    // ANIMATIONS
        bool animate = false;
        int animate_count = 0;
        int synth_menu_count = 0;
        int help_menu_count = 0;
        int stats_menu_count = 0;
        int animate_cycles = 6;
};

