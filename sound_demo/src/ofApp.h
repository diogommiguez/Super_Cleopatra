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
        double max_audio = 2;
    //MENUS
        menu synth_menu;
        menu mech_menu;
};

