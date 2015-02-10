#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    ofDisableArbTex();
    
    ofBackground(0, 0, 0);
    ofSetLogLevel(OF_LOG_VERBOSE);
    
    loadShaders();

    lutImage.loadImage("images/color_lut.png");
    ofSetWindowShape(800, 600);
    ofSetWindowPosition(0, 0);

}

//--------------------------------------------------------------
void ofApp::loadShaders() {
    ofLogVerbose() << "*** Loading Shaders ***";
    
    shaderRayTracer = shared_ptr<ofShader>(new ofShader());
    shaderRayTracer->load("shaders/volume_runner_renderer.vert", "shaders/volume_runner_renderer.frag");

}

//--------------------------------------------------------------
void ofApp::update(){



}

//--------------------------------------------------------------
void ofApp::draw(){


    glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
    
    float posX = ofMap(ofGetMouseX(), 0, ofGetWidth(),-2,2);
        float posY = ofMap(ofGetMouseY(), 0, ofGetHeight(),0,2);
    
        shaderRayTracer->begin();
        shaderRayTracer->setUniform2f("resolution", ofGetWidth(),ofGetHeight());
        shaderRayTracer->setUniform2f("mouse",posX,posY);
        shaderRayTracer->setUniformTexture("color_image", lutImage, 5);
        shaderRayTracer->setUniform1f("tanHalfFov", 0.57735);
        ofRect(-1,-1,2,2);
        shaderRayTracer->end();



    
  
}

//--------------------------------------------------------------
void ofApp::exit(){

}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    
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
void ofApp::windowResized(int w, int h){

    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}




