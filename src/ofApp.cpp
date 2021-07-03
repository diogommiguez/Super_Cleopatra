#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetBackgroundAuto(false);
    ofSetCircleResolution(100);
    
    // AUDIO DRIVER---------------------------------------
    ofSoundStreamListDevices(); //--> PRINT O DEVICE QUE A GENTE QUER USAR PARA O OUTPUT. DEFAULTS TO AS COLUnAS DO Pêssê
    //soundstream.setDeviceID(2); //-->BLACKHOLE
    soundstream.setup(this, 2, 0, 44100, 512, 4); // 2 output channels (stereo), 0 input channels
    
    
    // NOTAS ---------------------------------------------
    
    notes.push_back(1046.50*0.25);
    notes.push_back(1174.66*0.25);
    notes.push_back(1396.91*0.25);
    notes.push_back(1567.98*0.25);
    notes.push_back(1760.00*0.25);
    
    notes.push_back(1046.50*0.5);
    notes.push_back(1174.66*0.5);
    notes.push_back(1396.91*0.5);
    notes.push_back(1567.98*0.5);
    notes.push_back(1760.00*0.5);
    
    notes.push_back(1046.50);
    notes.push_back(1174.66);
    notes.push_back(1396.91);
    notes.push_back(1567.98);
    notes.push_back(1760.00);
    

    // SYNTH MENU ---------------------------------------------

    synth_menu.menu_width = 450;
    synth_menu.menu_height = 220;

    synth_menu.vecToggles.push_back(toggle(synth_menu.menu_x+0*synth_menu.menu_width/10.0+15,synth_menu.menu_y+2*synth_menu.menu_height/3.+40));
    synth_menu.vecToggles.push_back(toggle(synth_menu.menu_x+1*synth_menu.menu_width/10.0+15,synth_menu.menu_y+2*synth_menu.menu_height/3.+40));
    synth_menu.vecToggles.push_back(toggle(synth_menu.menu_x+2*synth_menu.menu_width/10.0+15,synth_menu.menu_y+2*synth_menu.menu_height/3.+40));
    
    synth_menu.vecSliders.push_back(slider(synth_menu.menu_x+0*synth_menu.menu_width/10.0+15,synth_menu.menu_y+synth_menu.menu_height/3.));
    synth_menu.vecSliders.push_back(slider(synth_menu.menu_x+1*synth_menu.menu_width/10.0+15,synth_menu.menu_y+synth_menu.menu_height/3.));
    synth_menu.vecSliders.push_back(slider(synth_menu.menu_x+2*synth_menu.menu_width/10.0+15,synth_menu.menu_y+synth_menu.menu_height/3.));
    
    synth_menu.vecSliders.push_back(slider(synth_menu.menu_x+4*synth_menu.menu_width/10.0+10,synth_menu.menu_y+synth_menu.menu_height/3.));
    synth_menu.vecSliders.push_back(slider(synth_menu.menu_x+5*synth_menu.menu_width/10.0+10,synth_menu.menu_y+synth_menu.menu_height/3.));
    synth_menu.vecSliders.push_back(slider(synth_menu.menu_x+6*synth_menu.menu_width/10.0+10,synth_menu.menu_y+synth_menu.menu_height/3.));
    
    synth_menu.vecSliders.push_back(slider(synth_menu.menu_x+8*synth_menu.menu_width/10.0,synth_menu.menu_y+synth_menu.menu_height/3.));
    synth_menu.vecSliders.push_back(slider(synth_menu.menu_x+9*synth_menu.menu_width/10.0,synth_menu.menu_y+synth_menu.menu_height/3.));
    
    synth_menu.vecSliders.push_back(slider(synth_menu.menu_x+8*synth_menu.menu_width/10.0,synth_menu.menu_y+synth_menu.menu_height/3.));
    synth_menu.vecSliders.push_back(slider(synth_menu.menu_x+9*synth_menu.menu_width/10.0,synth_menu.menu_y+synth_menu.menu_height/3.));
    synth_menu.vecSliders.push_back(slider(synth_menu.menu_x+8*synth_menu.menu_width/10.0,synth_menu.menu_y+synth_menu.menu_height/3.));
    synth_menu.vecSliders.push_back(slider(synth_menu.menu_x+9*synth_menu.menu_width/10.0,synth_menu.menu_y+synth_menu.menu_height/3.));
    
    synth_menu.vecToggles.push_back(toggle(synth_menu.menu_x+0*synth_menu.menu_width/10.0+15,synth_menu.menu_y+2*synth_menu.menu_height/3.+40));
    
    
    // HELP MENU ---------------------------------------------
    
    help_menu.pop_menu = true;
    
    help_menu.menu_width = 350;
    help_menu.menu_height = 120;

    // pos inicial em relação ao synth menu
    help_menu.menu_x = ofGetWidth()/2.0-help_menu.menu_width/2.0;
    help_menu.menu_y = ofGetHeight()/2.0-help_menu.menu_height/2.0;
    
}

//--------------------------------------------------------------
void ofApp::update(){

    // ------------------------------------------------------------------
    // ---------------------------- BOLAS -------------------------------
    // ------------------------------------------------------------------
    
    for(int i = 0; i<balls.size() and !pause; i++){
        if(balls[i].get_posy()>ofGetHeight()+5){
            balls.erase(balls.begin() + i);
        }
        if(balls[i].hit_note==true){
            phase[i] = 0;
        }
        balls[i].evolve();
    }
    
    // ------------------------------------------------------------------
    // --------------------- MENU SINTETIZADOR --------------------------
    // ------------------------------------------------------------------
    
    synth_menu.vecToggles[0].setup(synth_menu.menu_x+0*synth_menu.menu_width/16.0+20,synth_menu.menu_y+2*synth_menu.menu_height/3.+40);
    synth_menu.vecToggles[1].setup(synth_menu.menu_x+1*synth_menu.menu_width/16.0+20,synth_menu.menu_y+2*synth_menu.menu_height/3.+40);
    synth_menu.vecToggles[2].setup(synth_menu.menu_x+2*synth_menu.menu_width/16.0+20,synth_menu.menu_y+2*synth_menu.menu_height/3.+40);
    
    synth_menu.vecSliders[0].update(synth_menu.menu_x+0*synth_menu.menu_width/16.0+20,synth_menu.menu_y+synth_menu.menu_height/3.);
    synth_menu.vecSliders[1].update(synth_menu.menu_x+1*synth_menu.menu_width/16.0+20,synth_menu.menu_y+synth_menu.menu_height/3.);
    synth_menu.vecSliders[2].update(synth_menu.menu_x+2*synth_menu.menu_width/16.0+20,synth_menu.menu_y+synth_menu.menu_height/3.);
    
    synth_menu.vecSliders[3].update(synth_menu.menu_x+4*synth_menu.menu_width/16.0+20,synth_menu.menu_y+synth_menu.menu_height/3.);
    synth_menu.vecSliders[4].update(synth_menu.menu_x+5*synth_menu.menu_width/16.0+20,synth_menu.menu_y+synth_menu.menu_height/3.);
    synth_menu.vecSliders[5].update(synth_menu.menu_x+6*synth_menu.menu_width/16.0+20,synth_menu.menu_y+synth_menu.menu_height/3.);
    
    synth_menu.vecSliders[6].update(synth_menu.menu_x+8*synth_menu.menu_width/16.0+20,synth_menu.menu_y+synth_menu.menu_height/3.);
    synth_menu.vecSliders[7].update(synth_menu.menu_x+9*synth_menu.menu_width/16.0+20,synth_menu.menu_y+synth_menu.menu_height/3.);
    
    synth_menu.vecSliders[8].update(synth_menu.menu_x+11*synth_menu.menu_width/16.0+15,synth_menu.menu_y+synth_menu.menu_height/3.);
    synth_menu.vecSliders[9].update(synth_menu.menu_x+12*synth_menu.menu_width/16.0+15,synth_menu.menu_y+synth_menu.menu_height/3.);
    synth_menu.vecSliders[10].update(synth_menu.menu_x+13*synth_menu.menu_width/16.0+25,synth_menu.menu_y+synth_menu.menu_height/3.);
    synth_menu.vecSliders[11].update(synth_menu.menu_x+14*synth_menu.menu_width/16.0+25,synth_menu.menu_y+synth_menu.menu_height/3.);
    
    synth_menu.vecToggles[3].setup(synth_menu.menu_x+13*synth_menu.menu_width/16.0+5,synth_menu.menu_y+2*synth_menu.menu_height/3.+40);

    // ------------------------------------------------
    // --------------- PARAMS ANIMACOES ---------------
    // ------------------------------------------------
    
    if(animate and animate_count < animate_cycles){
            animate_count++;
    }else if (!animate and animate_count > 0) {
            animate_count--;
    }
    if(synth_menu.pop_menu and synth_menu_count < animate_cycles){
        synth_menu_count++;
    }else if (!(synth_menu.pop_menu) and synth_menu_count > 0) {
        synth_menu_count--;
    }
    if(help_menu.pop_menu and help_menu_count < animate_cycles){
        help_menu_count++;
    }else if (!(help_menu.pop_menu) and help_menu_count > 0) {
        help_menu_count--;
    }
    
    // ------------------------------------------------
    // --------------- PARAMETROS MENUS ---------------
    // ------------------------------------------------
    attack      = synth_menu.vecSliders[3].get_value()*5.0+1;
    decay       = synth_menu.vecSliders[4].get_value()*5.0+1;
    volume      = get_volume((synth_menu.vecSliders[5].get_value()));
    Filterfreq  = get_frequency(synth_menu.vecSliders[6].get_value());
    Resonance   = synth_menu.vecSliders[7].get_value()/5.0;

    wvforms[0]  = synth_menu.vecToggles[0].get_status();
    wvforms[1]  = synth_menu.vecToggles[1].get_status();
    wvforms[2]  = synth_menu.vecToggles[2].get_status();
    

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofColor colorOne;
    ofColor colorTwo;

//    colorOne.set(ofMap(animate_count, 0, animate_cycles, 50, 255),
//                 ofMap(animate_count, 0, animate_cycles, 25, 0),
//                 ofMap(animate_count, 0, animate_cycles, 200, 100));
    
    int delay = 20;
    colorOne.setHsb(140,200,200,ofMap(delay,0,100,255,80));
    colorTwo.setHsb(200,200,200,ofMap(delay,0,100,255,80));
    
    ofBackgroundGradient(colorOne, colorTwo, OF_GRADIENT_LINEAR);
    
    for(int i =0; i<notes.size(); i++){
        ofSetColor(i*255/notes.size(), 127*(1+sin(i/2.0)), 255-i*255/notes.size());
        ofDrawRectangle(i*ofGetWidth()/notes.size(), ofGetHeight()-ofMap(animate_count, 0, animate_cycles, 15, 0), (i+1)*ofGetWidth()/notes.size(), ofGetHeight());
    }
    
    for(int i = 0; i<balls.size() ; i++){
        ofSetColor(balls[i].get_color());
        ofDrawCircle(balls[i].get_posx(), balls[i].get_posy(), balls[i].get_radius());
    }
    
    // -------------------------------------------------------------------------------------------
    // --------------------------  MENU SINTETIZADOR  --------------------------------------------
    // -------------------------------------------------------------------------------------------
    
    // CAIXINHAS DE MENU -------------
    ofColor color;

    color.setHsb(0, 0, 100,ofMap(synth_menu_count, 0, animate_cycles, 0, 255));
    ofSetColor(color);
    ofDrawRectangle(synth_menu.menu_x-5, synth_menu.menu_y-5, synth_menu.menu_width+10, synth_menu.menu_height+10);

    color.setHsb(0, 0, 150,ofMap(synth_menu_count, 0, animate_cycles, 0, 255));
    ofSetColor(color);
    
    // ---------------------------------------------------------------
    ofTranslate(synth_menu.menu_x, synth_menu.menu_y); // BEGIN OF TRANSLATE
    // ---------------------------------------------------------------
    
    ofDrawRectangle(0, 0, 4*synth_menu.menu_width/16.0-2.5, synth_menu.menu_height);
    ofDrawRectangle(4*synth_menu.menu_width/16.0+2.5, 0, 4*synth_menu.menu_width/16.0-5, synth_menu.menu_height);
    ofDrawRectangle(8*synth_menu.menu_width/16.0+2.5, 0, 3*synth_menu.menu_width/16.0-5, synth_menu.menu_height);
    ofDrawRectangle(11*synth_menu.menu_width/16.0+2.5, 0, 5*synth_menu.menu_width/16.0-2.5, synth_menu.menu_height);
    
    // LETRAS E SIMBOLOS ------------------
    color.setHsb(0, 0, 0,ofMap(synth_menu_count, 0, animate_cycles, 0, 255));
    ofSetColor(color);
    
    ofDrawBitmapString("OSCILLATOR", 1*synth_menu.menu_width/16.0-10,synth_menu.menu_height/8.0-5);
    ofDrawBitmapString("AMPLIFIER", 5*synth_menu.menu_width/16.0-10,synth_menu.menu_height/8.0-5);
    ofDrawBitmapString("FILTER", 9*synth_menu.menu_width/16.0-10,synth_menu.menu_height/8.0-5);
    ofDrawBitmapString("EFFECTS", 13*synth_menu.menu_width/16.0-15,synth_menu.menu_height/8.0-5);
    
    // BOLD LOL
    ofDrawBitmapString("OSCILLATOR", 1*synth_menu.menu_width/16.0-9,synth_menu.menu_height/8.0-5);
    ofDrawBitmapString("AMPLIFIER", 5*synth_menu.menu_width/16.0-9,synth_menu.menu_height/8.0-5);
    ofDrawBitmapString("FILTER", 9*synth_menu.menu_width/16.0-9,synth_menu.menu_height/8.0-5);
    ofDrawBitmapString("EFFECTS", 13*synth_menu.menu_width/16.0-14,synth_menu.menu_height/8.0-5);
    
    ofDrawBitmapString("REVERB",11*synth_menu.menu_width/16.0+18,synth_menu.menu_height/3.-28);
    ofDrawBitmapString("DELAY",13*synth_menu.menu_width/16.0+30,synth_menu.menu_height/3.-28);
    
    ofDrawCircle(0*synth_menu.menu_width/16.0+30,synth_menu.menu_height/3.-20, 10);
    ofDrawRectangle(1*synth_menu.menu_width/16.0+20,synth_menu.menu_height/3.-30, 20,20);
    ofDrawTriangle( 2*synth_menu.menu_width/16.0+20, synth_menu.menu_height/3.-10,
                    2*synth_menu.menu_width/16.0+30, synth_menu.menu_height/3.-30,
                    2*synth_menu.menu_width/16.0+40, synth_menu.menu_height/3.-10);
    
    
    color.setHsb(170, 255, 255,ofMap(synth_menu_count, 0, animate_cycles, 0, 255));
    ofSetColor(color);
    
    ofDrawBitmapString("ATT", 4*synth_menu.menu_width/16.0+18,synth_menu.menu_height/3.-20);
    ofDrawBitmapString("DEC", 5*synth_menu.menu_width/16.0+18,synth_menu.menu_height/3.-20);
    ofDrawBitmapString("VOL", 6*synth_menu.menu_width/16.0+18,synth_menu.menu_height/3.-20);
    
    ofDrawBitmapString("FIL",8*synth_menu.menu_width/16.0+18,synth_menu.menu_height/3.-20);
    ofDrawBitmapString("RES",9*synth_menu.menu_width/16.0+18,synth_menu.menu_height/3.-20);
    
    ofDrawBitmapString("TIME",11*synth_menu.menu_width/16.0+8,synth_menu.menu_height/3.-10);
    ofDrawBitmapString("FBK",12*synth_menu.menu_width/16.0+13,synth_menu.menu_height/3.-10);
    ofDrawBitmapString("SIZE",13*synth_menu.menu_width/16.0+18,synth_menu.menu_height/3.-10);
    ofDrawBitmapString("FBK",14*synth_menu.menu_width/16.0+23,synth_menu.menu_height/3.-10);
   
    // ---------------------------------------------------------------
    ofTranslate(-synth_menu.menu_x, -synth_menu.menu_y); // END OF TRANSLATE
    // ---------------------------------------------------------------
    
    // TOGGLES E SLIDERS
    for(int i =0; i<synth_menu.vecToggles.size(); i++){
        synth_menu.vecToggles[i].run();
    }
    for(int i =0; i<synth_menu.vecSliders.size(); i++){
        synth_menu.vecSliders[i].run();
    }
    
    // -------------------------------------------------------------------------------------------
    // ----------------------------------   HELP MENU  --------------------------------------------
    // --------------------------------------------------------------------------------------------
        
    ofTranslate(help_menu.menu_x, help_menu.menu_y);
    
    color.setHsb(0,0,100,ofMap(help_menu_count, 0, animate_cycles, 0, 255));
    ofSetColor(color);
    ofDrawRectangle(-5, -5, help_menu.menu_width+10, help_menu.menu_height+10+30);
    
    color.setHsb(140,100,255,ofMap(help_menu_count, 0, animate_cycles, 0, 210));
    ofSetColor(color);
    ofDrawRectangle(0, 0, help_menu.menu_width, 25);
    
    color.setHsb(200,255,255,ofMap(help_menu_count, 0, animate_cycles, 0, 210));
    ofSetColor(color);
    ofDrawBitmapString("SUPER CLEOPATRA", help_menu.menu_width/2.0-60, 15);
    ofDrawBitmapString("SUPER CLEOPATRA", help_menu.menu_width/2.0-59, 15);
    
    color.setHsb(0,0,150,ofMap(help_menu_count, 0, animate_cycles, 0, 255));
    ofSetColor(color);
    ofDrawRectangle(0, 30, help_menu.menu_width/2.0-2.5, help_menu.menu_height-35);
    ofDrawRectangle(help_menu.menu_width/2.0+2.5, 30, help_menu.menu_width/2.0-2.5, help_menu.menu_height-35);
    ofDrawRectangle(0, 30+help_menu.menu_height-30, help_menu.menu_width/2.0-2.5, 30);
    ofDrawRectangle(help_menu.menu_width/2.0+2.5, 30+help_menu.menu_height-30, help_menu.menu_width/2.0-2.5, 30);
    
    color.setHsb(0,0,0,ofMap(help_menu_count, 0, animate_cycles, 0, 150));
    ofSetColor(color);

    ofDrawBitmapString("b - place ball", 10,45);
    ofDrawBitmapString("b", 11,45);
    
    ofDrawBitmapString("g - ativate force", 10,70);
    ofDrawBitmapString("g", 11,70);
    
    ofDrawBitmapString("v - random\n    velocities", 10,95);
    ofDrawBitmapString("v", 11,95);
    
    ofDrawBitmapString("w - [de]activate\n    walls", help_menu.menu_width/2.0+2.5+10,45);
    ofDrawBitmapString("w",  help_menu.menu_width/2.0+2.5+11,45);
    
    ofDrawBitmapString("o - [de]activate\n    floor", help_menu.menu_width/2.0+2.5+10,75);
    ofDrawBitmapString("o",  help_menu.menu_width/2.0+2.5+11,75);
    
    ofDrawBitmapString("SPACEBAR - pause", help_menu.menu_width/2.0+2.5+10,105);
    ofDrawBitmapString("SPACEBAR",  help_menu.menu_width/2.0+2.5+11,105);
    
    ofDrawBitmapString("m - open/close\n    synth menu", 10,133);
    ofDrawBitmapString("m", 11,133);
    
    ofDrawBitmapString("h - open/close\n    this menu", help_menu.menu_width/2.0+2.5+10,133);
    ofDrawBitmapString("h",  help_menu.menu_width/2.0+2.5+11,133);
    
    ofTranslate(-help_menu.menu_x, -help_menu.menu_y);

}


//--------------------------------------------------------------
void ofApp::audioOut( ofSoundBuffer &outBuffer) {
    float sample;
    float FilteredOutput;
    
    double mix_total = (synth_menu.vecSliders[0].get_value() + synth_menu.vecSliders[1].get_value() + synth_menu.vecSliders[2].get_value() + 0.0001);
    double mix0      = (synth_menu.vecSliders[0].get_value() + 0.0001)/mix_total;
    double mix1      = (synth_menu.vecSliders[1].get_value() + 0.0001)/mix_total;
    double mix2      = (synth_menu.vecSliders[2].get_value() + 0.0001)/mix_total;
    
    //cout << "mix0 = " << mix0 << "\nmix1 = " << mix1 << "\nmix2 = " << mix2 << "\nmix_total = " << mix_total << endl;
    //bool will_normalize = false;
    
    //double wave[outBuffer.size()];

    for(int i = 0; i < outBuffer.size(); i += 2) {
        sample=0;
        for(int ball=0; ball < balls.size() ;ball++)
        {
            //sample += volume*(sin(notes[balls[ball].getNote()]*phase[ball]/512.0))*envelope(phase[ball]);
            if (wvforms[0]) sample += volume*mix0*envelope(phase[ball])*(sin(notes[balls[ball].getNote()]*phase[ball]/512.0));//SINE WAVE
            
            if (wvforms[1]) sample += volume*mix1*envelope(phase[ball])*(sin(notes[balls[ball].getNote()]*phase[ball]/512.0)>0?1:-1);//SQUARE WAVE
            
            if (wvforms[2]) sample += 0.4*volume*mix2*envelope(phase[ball])*fmod(notes[balls[ball].getNote()]*phase[ball]/512.0,TWO_PI);//TRIANGLE WAVE
            
            phase[ball] += 0.05;
        }
            
            FilteredOutput=myFilter.lores(sample,Filterfreq,Resonance);
            //if (FilteredOutput > 1) will_normalize = true;
        
            outBuffer[i] = FilteredOutput; // writing to the left channel
            outBuffer[i + 1] = FilteredOutput; // writing to the right channel
        
            //wave[i] = FilteredOutput; // writing to the left channel
            //wave[i + 1] = FilteredOutput; // writing to the right channel
    }
//    if (will_normalize)
//    {
//        double maximo = max(wave, outBuffer.size());
//        for (int i = 0; i < outBuffer.size(); i += 2)
//        {
//            outBuffer[i] = outBuffer[i]/maximo;       // writing to the left channel
//            outBuffer[i + 1] = outBuffer[i+1]/maximo; // writing to the right channel
//        }
//    }
}

//--------------------------------------------------------------
double ofApp::envelope(double phase){
    if(phase <= attack)
        return phase/attack;
    else if(phase < attack+decay)
        return (attack-phase)/decay + 1;
    else if(phase >= attack+decay)
        return 0;
    return 0;
}

//--------------------------------------------------------------
void ofApp::random_v(){
    double mod;
    double ang;
    for(int i = 0; i<balls.size(); i++){
        mod = ofRandom(300,2000);
        ang = ofRandom(0,2*PI);
        balls[i].set_v_x(balls[i].get_v_x()+mod*cos(ang));
        balls[i].set_v_y(balls[i].get_v_y()+mod*sin(ang));
    }
}

//--------------------------------------------------------------
void ofApp::floor(bool value){
    for(int i = 0; i<balls.size(); i++){
        balls[i].set_closed_floor(value);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch(key) {
        case 'f':
            ofToggleFullscreen();
            break;
        case 'q':
            OF_EXIT_APP(0);
            break;
        case 'v':
            random_v();
            break;
        case 'b':
            newBall(ofGetMouseX(),ofGetMouseY());
            break;
        case 'g':
            for(int i =0; i<balls.size(); i++){
                (balls[i].getmouse_g() == false) ? balls[i].setmouse_g(true) : balls[i].setmouse_g(false);
            }
            break;
        case 'm':
            (synth_menu.pop_menu == false) ? synth_menu.pop_menu = true : synth_menu.pop_menu = false;
            break;
        case 'h':
            (help_menu.pop_menu == false) ? help_menu.pop_menu = true : help_menu.pop_menu = false;
            break;
        case ' ':
            (pause == false) ? pause = true : pause = false;
            break;
        case 'o':
            animate = !animate;
            _floor = !_floor;
            floor(_floor);
            break;
        case 'w':
            close_walls();
            break;
    }
}

//--------------------------------------------------------------
void ofApp::close_walls(){
    for(int i =0; i<balls.size(); i++){
        balls[i].set_closed_walls();
    }
}

//--------------------------------------------------------------
void ofApp::newBall(int xball, int yball){
    Ball myball;
    myball.set_posx(xball);
    myball.set_posy(yball);
    myball.set_radius(ofRandom(10,20));
    myball.set_color(ofRandom(0,255));
    myball.nnotes = notes.size();
    myball.set_closed_floor(_floor);
    
    balls.push_back(myball);
    phase.push_back(attack+decay);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    if(synth_menu.pop_menu and synth_menu.dragged){
        synth_menu.menu_x = ofGetMouseX()-synth_menu.drag_distx;
        synth_menu.menu_y = ofGetMouseY()-synth_menu.drag_disty;
    } else if(help_menu.pop_menu and help_menu.dragged){
        help_menu.menu_x = ofGetMouseX()-help_menu.drag_distx;
        help_menu.menu_y = ofGetMouseY()-help_menu.drag_disty;
    }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    if(synth_menu.pop_menu and x>synth_menu.menu_x and x<synth_menu.menu_x+synth_menu.menu_width and y>synth_menu.menu_y and y<synth_menu.menu_y+25){
        synth_menu.drag_distx = ofGetMouseX()-synth_menu.menu_x;
        synth_menu.drag_disty = ofGetMouseY()-synth_menu.menu_y;
        synth_menu.dragged = true;
    } else if(help_menu.pop_menu and x>help_menu.menu_x and x<help_menu.menu_x+help_menu.menu_width and y>help_menu.menu_y and y<help_menu.menu_y+25){
        help_menu.drag_distx = ofGetMouseX()-help_menu.menu_x;
        help_menu.drag_disty = ofGetMouseY()-help_menu.menu_y;
        help_menu.dragged = true;
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    synth_menu.dragged = false;
    help_menu.dragged = false;
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
