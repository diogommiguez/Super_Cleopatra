/*
 Project Title:
 Description:
 Author: Diogo Miguez
 2021
*/

#include "ofMain.h"

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
        void getNote(double);
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
        void move();
        vector <Ball> balls;
        void open_floor();
    //audio
        void audioOut(ofSoundBuffer& );
        double envelope(double);
        vector<double> phase;
        double attack;
        double decay;
        int nballs;
		
};
