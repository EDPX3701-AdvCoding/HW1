#include "ofApp.h"

/*
i have a dream
*/


//--------------------------------------------------------------
void ofApp::setup(){
    midpoint = ofPoint(ofGetWindowWidth()/2.0f+10,ofGetWindowHeight()/3.0f); //define my points
    top = ofPoint(ofGetWindowWidth()/2.0f,20.0f);
}

//--------------------------------------------------------------
void ofApp::update(){
    float midpointMove = sin(ofGetElapsedTimef()/2.1)*150 + ofGetWindowWidth()/2.0f;
    float topMove = cos(ofGetElapsedTimef()*1.2)*100 + midpointMove;
    midpoint.x = midpointMove;
    top.x = topMove;

    myPolyline.curveTo(ofGetWindowWidth()/2.0f, ofGetWindowHeight());
    myPolyline.curveTo(ofGetWindowWidth()/2.0f, ofGetWindowHeight());
    myPolyline.curveTo(ofGetWindowWidth()/2.0f, ofGetWindowHeight()*0.75f);
    myPolyline.curveTo(midpoint);
    myPolyline.curveTo(top);
    myPolyline.curveTo(top);
    myPolyline.simplify();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(150);
    ofSetColor(ofColor::greenYellow);
    myPolyline.draw();
    ofColor green = ofColor::darkOliveGreen;
    
    float numPoints = myPolyline.size();
    for (int p=0; p<100; p+=1) {
        green.setBrightness(p*2+50);
        ofSetColor(green);
        ofVec3f point = myPolyline.getPointAtPercent(p/100.0);
        float floatIndex = p/100.0 * (numPoints-1);
        ofVec3f normal = myPolyline.getNormalAtIndexInterpolated(floatIndex) * (200-(p*2));
        ofLine(point-normal/2, point+normal/2);
    }
    
    
    
    myPolyline.clear();
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
