/*
 Project Title:
 Description:
 Author: Diogo Miguez
 2021
*/

#include "ofMain.h"
#include "ofxMaxim.h"

#include "menu.hpp"
#include "ball.hpp"
#include "func.hpp"


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
        vector<double> notes;
        //int nnotes = 7; // numero de notas
        // double notes[7] = {349.23,392.00,415.30,493.88,523.25,600,700};
    
        double Filterfreq;
        ofxMaxiFilter myFilter;
    //MENUS
        menu synth_menu;
        menu mech_menu;
};

