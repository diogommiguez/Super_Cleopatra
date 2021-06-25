#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    nballs = 3;
    for(int j =0;j<nballs;j++){
        phase.push_back(0);
    }
    attack = 100;
    decay = 30000;
    
    ofSoundStreamSetup(2, 0); // 2 output channels (stereo), 0 input channels
}

//--------------------------------------------------------------
void ofApp::audioOut( ofSoundBuffer &outBuffer) {
    float sample;
    for(int i = 0; i < outBuffer.size(); i += 2) {
        sample=0;
        for(int ball=0; ball < nballs ;ball++)
        {
            sample += sin(0.5*phase[ball])*envelope(phase[ball]); // generating a sine wave sample
            phase[ball] += 0.05;
        }
            //float sample = sin(phase)*envelope(phase) + sin(3.3*phase1)*envelope(phase1); // generating a sine wave sample
            outBuffer[i] = sample; // writing to the left channel
            outBuffer[i + 1] = sample; // writing to the right channel
    }
}

//--------------------------------------------------------------
double ofApp::envelope(double phase){
    if(phase <= attack)
        return phase/attack;
    else if(phase < attack+decay)
        return (attack-phase)/decay + 1;

}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch(key) {
        case 'f':
            ofToggleFullscreen();
            break;
        case 'a':
            phase[0]=0;
            break;
        case 'b':
            phase[1]=0;
            break;
        case 'c':
            phase[2]=0;
            break;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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
