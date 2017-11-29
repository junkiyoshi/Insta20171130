#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(30);
	ofBackground(255);
	ofSetWindowTitle("Insta");

	ofEnableDepthTest();

	this->light.setSpotlight();
	this->light.setPosition(0, 0, 600);
	this->light.setSpecularColor(ofFloatColor(1.0, 1.0, 1.0));
	this->light.setDiffuseColor(ofFloatColor(0.0, 0.0, 0.9));
	this->light.setAmbientColor(ofFloatColor(0.0, 0.0, 0.1));
	this->light.enable();
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {
	this->cam.begin();

	float radius = 300;
	int deg_span = 10;
	ofVec3f location;
	float size = ofVec3f(radius * cos(0), radius * sin(0), 0).distance(ofVec3f(radius * cos(deg_span * DEG_TO_RAD), radius * sin(deg_span * DEG_TO_RAD), 0));
	float h_size;

	for (float z = -300; z < 300; z += size) {
		for (int deg = 0; deg < 360; deg += deg_span) {

			location = ofVec3f(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD), z);
			h_size = 200 * ofNoise(location.x * 0.0035, location.y * 0.0035, location.z * 0.0035, ofGetFrameNum() * 0.01);

			ofPushMatrix();
			ofTranslate(location);
			ofRotate(deg);
			ofTranslate(-h_size / 2, 0);

			this->box.set(h_size, size, size);
			this->box.draw();

			ofPopMatrix();
		}
	}
	
	//this->light.draw();
	this->cam.end();
}

//--------------------------------------------------------------
int main() {
	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}