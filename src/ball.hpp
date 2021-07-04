#ifndef ball_hpp
#define ball_hpp

#include "ofMain.h"
#include "func.hpp"
#include "ofxMaxim.h"
#include <stdio.h>

class Ball : public ofBaseApp{
    // parametros da bola
        double posx;
        double posy;
        double v_y = 0;
        double v_x = 0;
        int radius;
        ofColor color;
    // constantes físicas
        double g = 10000;
        double a = 1000;
    // parametros da simulação
        int SAMPLE_RATE = 100;
        double dt = 1.0/SAMPLE_RATE;
    // variaveis booleanas / flags
        bool closed_floor = true; // chão está ou não a deixar passar as bolas
        bool closed_walls = true;
        bool caught = false; // a bola atual encontra-se ou não "capturada" pelo rato
        bool mouse_g = false; // a bola é graviticamente atraída ou não pelo rato
    // parametros musicais
        int note; // nota que vai tocar
    
    public:
        void set_posx(double);
        void move_x(double); // adiciona à posição x da bola
        void set_posy(double);
        void move_y(double); // adiciona à posição y da bola
        void set_radius(int);
        void set_color(int);
        void set_v_y(double);
        void set_v_x(double);
        const double get_posx();
        const double get_posy();
        const int get_radius();
        const ofColor get_color();
        const double get_v_x() {return v_x;};
        const double get_v_y();
        void evolve();
        void set_closed_floor(bool val) {closed_floor = val;};
        void set_closed_walls() {closed_walls = !closed_walls;};
        int getNote();
        bool hit_note = false;
        void setmouse_g(bool act) {mouse_g = act;};
        bool getmouse_g() {return mouse_g;};
        bool get_closed_floor() {return closed_floor;};
        bool get_closed_walls() {return closed_walls;};
        int nnotes = 7; // numero de notas possíveis
        ofxMaxiOsc Osc_sine;
        ofxMaxiOsc Osc_quad;
        ofxMaxiOsc Osc_trig;
};

#endif /* ball_hpp */
