//
//  ball.hpp
//  sound_demo
//
//  Created by Diogo Miguez on 27/06/2021.
//

#ifndef ball_hpp
#define ball_hpp

#include "ofMain.h"
#include "func.hpp"
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
        double g = 5000;
        double a = 1000;
    // parametros da simulação
        int SAMPLE_RATE = 100;
        double dt = 1.0/SAMPLE_RATE;
    // variaveis booleanas / flags
        bool closed_floor = true; // chão está ou não a deixar passar as bolas
        bool caught = false; // a bola atual encontra-se ou não "capturada" pelo rato
        bool mouse_g = false; // a bola é graviticamente atraída ou não pelo rato
    // parametros musicais
        int note; // nota que vai tocar
        int nnotes = 5; // numero de notas possíveis
        //double notes[5] = {261.63,277.18,329.63,349.23,415.30}; // frequências em Hertz
        double notes[5] = {349.23,392.00,415.30,493.88,523.25};
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
        const double get_v_y();
        void evolve();
        void set_closed_floor(bool val) {closed_floor = val;};
        int getNote();
        bool hit_note = false;
        void setmouse_g(bool act) {mouse_g = act;};
        bool getmouse_g() {return mouse_g;};
};

#endif /* ball_hpp */
