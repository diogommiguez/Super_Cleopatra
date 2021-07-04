#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetBackgroundAuto(false);
    ofSetCircleResolution(100);
    font.load("digital-7 (mono).ttf", 11);
    font_help_menu.load("digital-7 (mono).ttf", 13);
    font_bold.load("digital-7 (mono).ttf", 15);
    
    attack = 150;
    decay = 200;
    
    // AUDIO DRIVER---------------------------------------
    ofSoundStreamListDevices(); //--> PRINT O DEVICE QUE A GENTE QUER USAR PARA O OUTPUT. DEFAULTS TO AS COLUnAS DO Pêssê
    soundstream.setDeviceID(0); //-->BLACKHOLE
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
    help_menu.menu_height = 150;

    // pos inicial em relação ao synth menu
    help_menu.menu_x = ofGetWidth()/2.0-help_menu.menu_width/2.0;
    help_menu.menu_y = ofGetHeight()/2.0-help_menu.menu_height/2.0;
    
    // STATS MENU ---------------------------------------------
    stats_menu.menu_width = 100;
    stats_menu.menu_height = 110;
    
    stats_menu.menu_x = ofGetWidth()-2*stats_menu.menu_width;
    stats_menu.menu_y = stats_menu.menu_height;
    
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
    if(stats_menu.pop_menu and stats_menu_count < animate_cycles){
        stats_menu_count++;
    }else if (!(stats_menu.pop_menu) and stats_menu_count > 0) {
        stats_menu_count--;
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
    
    colorOne.setHsb(140,200,240,255);//ofMap(decay,1,501,255,80));
    colorTwo.setHsb(200,200,200,255);//ofMap(decay,1,501,255,80));
    
    ofBackgroundGradient(colorOne, colorTwo, OF_GRADIENT_LINEAR);
    
    for(int i =0; i<notes.size(); i++){
        ofSetColor(i*255/notes.size(), 127*(1+sin(i/2.0)), 255-i*255/notes.size());
        ofDrawRectangle(i*ofGetWidth()/notes.size(), ofGetHeight()-ofMap(animate_count, 0, animate_cycles, 15, 0), (i+1)*ofGetWidth()/notes.size(), ofGetHeight());
    }
    
    for(int i = 0; i<balls.size() ; i++){
        ofSetColor(balls[i].get_color());
        ofDrawCircle(balls[i].get_posx(), balls[i].get_posy(), balls[i].get_radius());
    }
    
    ofColor color;

    // -------------------------------------------------------------------------------------------
    // --------------------------  MENU SINTETIZADOR  --------------------------------------------
    // -------------------------------------------------------------------------------------------
    
    // CAIXINHAS DE MENU -------------

    if(synth_menu_count>0){
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
        
        font_bold.drawString("OSC", 1*synth_menu.menu_width/16.0+14,synth_menu.menu_height/8.0-5);
        font_bold.drawString("AMP", 5*synth_menu.menu_width/16.0+14,synth_menu.menu_height/8.0-5);
        font_bold.drawString("FILT", 9*synth_menu.menu_width/16.0-2,synth_menu.menu_height/8.0-5);
        font_bold.drawString("FX", 13*synth_menu.menu_width/16.0+5,synth_menu.menu_height/8.0-5);
        
        // BOLD LOL
        //ofDrawBitmapString("OSCILLATOR", 1*synth_menu.menu_width/16.0-9,synth_menu.menu_height/8.0-5);
        //ofDrawBitmapString("AMPLIFIER", 5*synth_menu.menu_width/16.0-9,synth_menu.menu_height/8.0-5);
        //ofDrawBitmapString("FILTER", 9*synth_menu.menu_width/16.0-9,synth_menu.menu_height/8.0-5);
        //ofDrawBitmapString("EFFECTS", 13*synth_menu.menu_width/16.0-14,synth_menu.menu_height/8.0-5);
        
        font_help_menu.drawString("REVERB",11*synth_menu.menu_width/16.0+18,synth_menu.menu_height/3.-28);
        font_help_menu.drawString("DELAY",13*synth_menu.menu_width/16.0+30,synth_menu.menu_height/3.-28);
        
        ofDrawCircle(0*synth_menu.menu_width/16.0+30,synth_menu.menu_height/3.-20, 10);
        ofDrawRectangle(1*synth_menu.menu_width/16.0+20,synth_menu.menu_height/3.-30, 20,20);
        ofDrawTriangle( 2*synth_menu.menu_width/16.0+20, synth_menu.menu_height/3.-10,
                        2*synth_menu.menu_width/16.0+30, synth_menu.menu_height/3.-30,
                        2*synth_menu.menu_width/16.0+40, synth_menu.menu_height/3.-10);
        
        
        color.setHsb(170, 255, 255,ofMap(synth_menu_count, 0, animate_cycles, 0, 255));
        ofSetColor(color);
        
        font.drawString("ATT", 4*synth_menu.menu_width/16.0+16,synth_menu.menu_height/3.-20);
        font.drawString("DEC", 5*synth_menu.menu_width/16.0+18,synth_menu.menu_height/3.-20);
        font.drawString("VOL", 6*synth_menu.menu_width/16.0+20,synth_menu.menu_height/3.-20);
        
        font.drawString("FILT",8*synth_menu.menu_width/16.0+16,synth_menu.menu_height/3.-20);
        font.drawString("RES",9*synth_menu.menu_width/16.0+20,synth_menu.menu_height/3.-20);
        
        font.drawString("TIME",11*synth_menu.menu_width/16.0+8,synth_menu.menu_height/3.-10);
        font.drawString("FBK",12*synth_menu.menu_width/16.0+15,synth_menu.menu_height/3.-10);
        font.drawString("SIZE",13*synth_menu.menu_width/16.0+19,synth_menu.menu_height/3.-10);
        font.drawString("FBK",14*synth_menu.menu_width/16.0+25,synth_menu.menu_height/3.-10);
       
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
    }
    
    // -------------------------------------------------------------------------------------------
    // ----------------------------------   HELP MENU  --------------------------------------------
    // --------------------------------------------------------------------------------------------
        
    if(help_menu_count>0){
        ofTranslate(help_menu.menu_x, help_menu.menu_y);
        
        color.setHsb(0,0,100,ofMap(help_menu_count, 0, animate_cycles, 0, 255));
        ofSetColor(color);
        ofDrawRectangle(-5, -5, help_menu.menu_width+10, help_menu.menu_height+10+30);
        
        color.setHsb(140,100,255,ofMap(help_menu_count, 0, animate_cycles, 0, 210));
        ofSetColor(color);
        ofDrawRectangle(0, 0, help_menu.menu_width, 25);
        
        color.setHsb(200,255,255,ofMap(help_menu_count, 0, animate_cycles, 0, 210));
        ofSetColor(color);
        font_bold.drawString("SUPER CLEOPATRA", help_menu.menu_width/2.0-60, 18);
        
        color.setHsb(0,0,150,ofMap(help_menu_count, 0, animate_cycles, 0, 255));
        ofSetColor(color);
        ofDrawRectangle(0, 30, help_menu.menu_width/2.0-2.5, help_menu.menu_height-35-30);
        ofDrawRectangle(help_menu.menu_width/2.0+2.5, 30, help_menu.menu_width/2.0-2.5, help_menu.menu_height-35-30);
        
        ofDrawRectangle(0, 30+help_menu.menu_height-30-30, help_menu.menu_width/2.0-2.5, 30);
        ofDrawRectangle(help_menu.menu_width/2.0+2.5, 30+help_menu.menu_height-30-30, help_menu.menu_width/2.0-2.5, 30);
        
        ofDrawRectangle(0, 30+help_menu.menu_height-30, help_menu.menu_width/2.0-2.5, 30);
        ofDrawRectangle(help_menu.menu_width/2.0+2.5, 30+help_menu.menu_height-30, help_menu.menu_width/2.0-2.5, 30);
        
        color.setHsb(0,0,0,ofMap(help_menu_count, 0, animate_cycles, 0, 150));
        ofSetColor(color);

        font.drawString("  - place ball", 10,48);
        font_help_menu.drawString("b", 11,48);
        font_help_menu.drawString("b", 10,48);

        font.drawString("         - change notes", 10,75);
        font_help_menu.drawString("Numbers", 11,75);
        font_help_menu.drawString("Numbers", 10,75);

        
        font.drawString("  - random velocities", 10,102);
        font_help_menu.drawString("v", 11,102);
        font_help_menu.drawString("v", 10,102);
        
        font.drawString("  - open/close walls", help_menu.menu_width/2.0+2.5+10,48);
        font_help_menu.drawString("w",  help_menu.menu_width/2.0+2.5+11,48);
        font_help_menu.drawString("w",  help_menu.menu_width/2.0+2.5+10,48);
        
        font.drawString("  - open/close floor", help_menu.menu_width/2.0+2.5+10,75);
        font_help_menu.drawString("o",  help_menu.menu_width/2.0+2.5+11,75);
        font_help_menu.drawString("o",  help_menu.menu_width/2.0+2.5+10,75);
        
        font.drawString("  - activate force", help_menu.menu_width/2.0+2.5+10,102);
        font_help_menu.drawString("g",  help_menu.menu_width/2.0+2.5+11,102);
        font_help_menu.drawString("g",  help_menu.menu_width/2.0+2.5+10,102);
        
        font.drawString("          - pause", help_menu.menu_width/2.0+2.5+10,142);
        font_help_menu.drawString("SPACEBAR", help_menu.menu_width/2.0+2.5+11,142);
        font_help_menu.drawString("SPACEBAR", help_menu.menu_width/2.0+2.5+10,142);

        font.drawString("  - quit", help_menu.menu_width/2.0+2.5+10,137+25);
        font_help_menu.drawString("q", help_menu.menu_width/2.0+2.5+11,137+25);
        font_help_menu.drawString("q", help_menu.menu_width/2.0+2.5+10,137+25);

        font.drawString("  - pop synth menu",10,135);
        font_help_menu.drawString("m", 11,135);
        font_help_menu.drawString("m", 10,135);

        font.drawString("  - pop this menu", 10,137+15);
        font_help_menu.drawString("h",  11,137+15);
        font_help_menu.drawString("h",  10,137+15);

        font.drawString("  - pop stats menu", 10,137+32);
        font_help_menu.drawString("s",  11,137+32);
        font_help_menu.drawString("s",  10,137+32);

        ofTranslate(-help_menu.menu_x, -help_menu.menu_y);
    }
    
    // -------------------------------------------------------------------------------------------
    // ---------------------------------  STATS MENU  --------------------------------------------
    // -------------------------------------------------------------------------------------------
        
    if(stats_menu_count>0){
        ofTranslate(stats_menu.menu_x, stats_menu.menu_y);
        
        color.setHsb(0,0,100,ofMap(stats_menu_count, 0, animate_cycles, 0, 255));
        ofSetColor(color);
        ofDrawRectangle(-5, -5, stats_menu.menu_width+10, stats_menu.menu_height+10+30);
        
        color.setHsb(140,100,255,ofMap(stats_menu_count, 0, animate_cycles, 0, 210));
        ofSetColor(color);
        ofDrawRectangle(0, 0, stats_menu.menu_width, 25);
        
        color.setHsb(200,255,255,ofMap(stats_menu_count, 0, animate_cycles, 0, 210));
        ofSetColor(color);
        font_bold.drawString("STATS", stats_menu.menu_width/2.0-22, 17);
        
        color.setHsb(0,0,150,ofMap(stats_menu_count, 0, animate_cycles, 0, 255));
        ofSetColor(color);
        ofDrawRectangle(0, 30, stats_menu.menu_width, stats_menu.menu_height);
        
        color.setHsb(0,0,0,ofMap(stats_menu_count, 0, animate_cycles, 0, 150));
        ofSetColor(color);

        font_help_menu.drawString("Nballs", 7,45);
        font_help_menu.drawString("Nballs", 8,45);
        
        string nballs = to_string(balls.size());
        
        font_help_menu.drawString(nballs, 80,45);
        
        if(_g) {
            font_help_menu.drawString("Force", 7,67);
            font_help_menu.drawString("Force", 8,67);
            font_help_menu.drawString("ON", 75,67);
        } else {
            font_help_menu.drawString("Force ", 7,67);
            font_help_menu.drawString("Force ", 8,67);
            font_help_menu.drawString("OFF", 71,67);
        }
        
        if(_floor){
            font_help_menu.drawString("Floor  ", 7,89);
            font_help_menu.drawString("Floor  ", 8,89);
            font_help_menu.drawString("ON", 75,89);
        } else {
            font_help_menu.drawString("Floor   ", 7,89);
            font_help_menu.drawString("Floor  ", 8,89);
            font_help_menu.drawString("OFF", 71,89);
        }
        
        if(_walls){
            font_help_menu.drawString("Walls   ", 7,111);
            font_help_menu.drawString("Walls   ", 8,111);
            font_help_menu.drawString("ON", 75,111);
        } else {
            font_help_menu.drawString("Walls  ", 7,111);
            font_help_menu.drawString("Walls  ", 8,111);
            font_help_menu.drawString("OFF", 71,111);
        }
        
        font_help_menu.drawString("Notes  ", 7,133);
        font_help_menu.drawString("Notes  ", 8,133);
        
        switch(note_sel) {
            case 1:
                font_help_menu.drawString("PENTA ", 57,133);
                break;
            case 2:
                 font_help_menu.drawString("Cm7 ", 70,133);
                break;
            case 3:
                 font_help_menu.drawString("Fm7 ", 70,133);
                break;
            case 4:
                 font_help_menu.drawString("Bb7 ", 70,133);
                break;
            case 5:
                 font_help_menu.drawString("EbM7 ", 66,133);
                break;
            case 6:
                 font_help_menu.drawString("AbM7 ", 66,133);
                break;
            case 7:
                 font_help_menu.drawString("DbM7 ", 66,133);
                break;
            case 8:
                 font_help_menu.drawString("Gm7 ", 70,133);
                break;
            case 9:
                 font_help_menu.drawString("F ", 75,133);
                break;
            case 0:
                 font_help_menu.drawString("G7b6 ", 66,133);
                break;
        }
        
        ofTranslate(-stats_menu.menu_x, -stats_menu.menu_y);
    }
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
//        balls[i].set_v_x(balls[i].get_v_x()+mod*cos(ang));
//        balls[i].set_v_y(balls[i].get_v_y()+mod*sin(ang));
        balls[i].set_v_x(balls[i].get_v_x()+((int)ofRandom(-10,10))*100);
        balls[i].set_v_y(balls[i].get_v_x()+((int)ofRandom(-20,5))*100);
    }
}

//--------------------------------------------------------------
void ofApp::floor(bool value){
    for(int i = 0; i<balls.size(); i++){
        balls[i].set_closed_floor(value);
    }
}

//--------------------------------------------------------------
void ofApp::setNotes(int escala){
    switch(escala) {
        case 1:
            notes[0]=(1046.50*0.25);
            notes[1]=(1174.66*0.25);
            notes[2]=(1396.91*0.25);
            notes[3]=(1567.98*0.25);
            notes[4]=(1760.00*0.25);
            
            notes[5]=(1046.50*0.5);
            notes[6]=(1174.66*0.5);
            notes[7]=(1396.91*0.5);
            notes[8]=(1567.98*0.5);
            notes[9]=(1760.00*0.5);
            
            notes[10]=(1046.50);
            notes[11]=(1174.66);
            notes[12]=(1396.91);
            notes[13]=(1567.98);
            notes[14]=(1760.00);
            break;
        case 2:
            notes[0]=(1046.50*0.25);
            notes[1]=(1244.51*0.25);
            notes[2]=(1567.98*0.25);
            notes[3]=(1864.66*0.25);
            
            notes[4]=(1046.50*0.55);
            notes[5]=(1244.51*0.50);
            notes[6]=(1567.98*0.50);
            notes[7]=(1864.66*0.50);
            
            notes[8]= (1046.50*1);
            notes[9]= (1244.51*1);
            notes[10]=(1567.98*1);
            notes[11]=(1864.66*1);
            
            notes[12]=(1046.50*2);
            notes[13]=(1244.51*2);
            notes[14]=(1567.98*2);
            break;
        case 3:
            notes[0]=(1046.50 *0.25);
            notes[1]=(1244.51*0.25);
            notes[2]=(1396.91*0.25);
            notes[3]=(1661.22*0.25);
            
            notes[4]=(1046.50*0.55);
            notes[5]=(1244.51*0.50);
            notes[6]=(1396.91*0.50);
            notes[7]=(1661.22*0.50);
            
            notes[8]= (1046.50);
            notes[9]= (1244.51);
            notes[10]=(1396.91);
            notes[11]=(1661.22);
            
            notes[12]=(1046.50*2);
            notes[13]=(1244.51*2);
            notes[14]=(1396.91*2);
            break;
        case 4:
            notes[0]=(932.33 *0.25);
            notes[1]=(1174.66*0.25);
            notes[2]=(1396.91*0.25);
            notes[3]=(1661.22*0.25);
            
            notes[4]=(932.33 *0.55);
            notes[5]=(1174.66*0.50);
            notes[6]=(1396.91*0.50);
            notes[7]=(1661.22*0.50);
            
            notes[8]= (932.33 );
            notes[9]= (1174.66);
            notes[10]=(1396.91);
            notes[11]=(1661.22);
            
            notes[12]=(932.33 *2);
            notes[13]=(1174.66*2);
            notes[14]=(1396.91*2);
            break;
        case 5:
            notes[0]=(932.33 *0.25);
            notes[1]=(1174.66*0.25);
            notes[2]=(1244.51*0.25);
            notes[3]=(1567.98*0.25);
            
            notes[4]=(932.33 *0.50);
            notes[5]=(1174.66*0.50);
            notes[6]=(1244.51*0.50);
            notes[7]=(1567.98*0.50);
            
            notes[8]= (932.33 );
            notes[9]= (1174.66);
            notes[10]=(1244.51);
            notes[11]=(1567.98);
            
            notes[12]=(932.33 *2);
            notes[13]=(1174.66*2);
            notes[14]=(1244.51*2);
            break;
        case 6:
            notes[0]=(830.61 *0.25);
            notes[1]=(1046.50*0.25);
            notes[2]=(1244.51*0.25);
            notes[3]=(1567.98*0.25);
            
            notes[4]=(830.61 *0.50);
            notes[5]=(1046.50*0.50);
            notes[6]=(1244.51*0.50);
            notes[7]=(1567.98*0.50);
            
            notes[8]= (830.61 );
            notes[9]= (1046.50);
            notes[10]=(1244.51);
            notes[11]=(1567.98);
            
            notes[12]=(830.61*2 );
            notes[13]=(1046.50*2);
            notes[14]=(1244.51*2);
            break;
        case 7:
            notes[0]=(1108.73*0.25);
            notes[1]=(1396.91*0.25);
            notes[2]=(1567.98*0.25);
            notes[3]=(1864.66*0.25);
            
            notes[4]=(1108.73*0.55);
            notes[5]=(1396.91*0.50);
            notes[6]=(1567.98*0.50);
            notes[7]=(1864.66*0.50);
            
            notes[8]= (1108.73*1);
            notes[9]= (1396.91*1);
            notes[10]=(1567.98*1);
            notes[11]=(1864.66*1);
            
            notes[12]=(1108.73*2);
            notes[13]=(1396.91*2);
            notes[14]=(1567.98*2);
            break;
        case 8:
            notes[0]=(783.99 *0.25);
            notes[1]=(932.33 *0.25);
            notes[2]=(1174.66*0.25);
            notes[3]=(1244.51*0.25);
            
            notes[4]=(783.99*0.50);
            notes[5]=(932.33 *0.50);
            notes[6]=(1174.66 *0.50);
            notes[7]=(1244.51*0.50);
            
            notes[8]=(783.99);
            notes[9]=(932.33 );
            notes[10]=(1174.66 );
            notes[11]=(1244.51 );
            
            notes[12]=(783.99 *2);
            notes[13]=(932.33 *2);
            notes[14]=(1174.66*2);
            break;
        case 9:
            notes[0]=(1046.50 *0.25);
            notes[1]=(1244.51*0.25);
            notes[2]=(1396.91*0.25);
            notes[3]=(1760.00*0.25);
            
            notes[4]=(1046.50*0.50);
            notes[5]=(1244.51*0.50);
            notes[6]=(1396.91*0.50);
            notes[7]=(1760.00*0.50);
            
            notes[8]= (1046.50);
            notes[9]= (1244.51);
            notes[10]=(1396.91);
            notes[11]=(1760.00);
            
            notes[12]=(1046.50*2);
            notes[13]=(1244.51*2);
            notes[14]=(1396.91*2);
            break;
        case 0:
            notes[0]=(783.99 *0.25);
            notes[1]=(987.77 *0.25);
            notes[2]=(1174.66*0.25);
            notes[3]=(1244.51*0.25);
            notes[4]=(1396.91*0.25);
            
            notes[5]=(783.99 *0.50);
            notes[6]=(987.77 *0.50);
            notes[7]=(1174.66*0.50);
            notes[8]=(1244.51*0.50);
            notes[9]=(1396.91*0.50);
            
            notes[10]=(783.99 );
            notes[11]=(987.77 );
            notes[12]=(1174.66);
            notes[13]=(1244.51);
            notes[14]=(1396.91);
            break;
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
            (_g == false) ? _g = true : _g = false;
            break;
        case 'm':
            (synth_menu.pop_menu == false) ? synth_menu.pop_menu = true : synth_menu.pop_menu = false;
            break;
        case 'h':
            (help_menu.pop_menu == false) ? help_menu.pop_menu = true : help_menu.pop_menu = false;
            break;
        case 's':
            (stats_menu.pop_menu == false) ? stats_menu.pop_menu = true : stats_menu.pop_menu = false;
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
            (_walls == false) ? _walls = true : _walls = false;
            break;
        case '1':
            setNotes(1);
            note_sel = 1;
            break;
        case '2':
            setNotes(2);
            note_sel = 2;
            break;
        case '3':
            setNotes(3);
            note_sel = 3;
            break;
        case '4':
            setNotes(4);
            note_sel = 4;
            break;
        case '5':
            setNotes(5);
            note_sel = 5;
            break;
        case '6':
            setNotes(6);
            note_sel = 6;
            break;
        case '7':
            setNotes(7);
            note_sel = 7;
            break;
        case '8':
            setNotes(8);
            note_sel = 8;
            break;
        case '9':
            setNotes(9);
            note_sel = 9;
            break;
        case '0':
            setNotes(0);
            note_sel = 0;
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
    } else if(stats_menu.pop_menu and stats_menu.dragged){
        stats_menu.menu_x = ofGetMouseX()-stats_menu.drag_distx;
        stats_menu.menu_y = ofGetMouseY()-stats_menu.drag_disty;
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
    } else if(stats_menu.pop_menu and x>stats_menu.menu_x and x<stats_menu.menu_x+stats_menu.menu_width and y>stats_menu.menu_y and y<stats_menu.menu_y+25){
        stats_menu.drag_distx = ofGetMouseX()-stats_menu.menu_x;
        stats_menu.drag_disty = ofGetMouseY()-stats_menu.menu_y;
        stats_menu.dragged = true;
    }
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    synth_menu.dragged = false;
    help_menu.dragged = false;
    stats_menu.dragged = false;
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
