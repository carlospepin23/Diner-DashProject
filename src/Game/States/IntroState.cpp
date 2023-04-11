#include "IntroState.h"

IntroState::IntroState() {
	string text = "OK, Understood!";
	startButton = new Button((ofGetWidth()/2)-65, (ofGetHeight()/2)-50, 64, 50, text);
}
void IntroState::tick() {
	startButton->tick();
	if(startButton->wasPressed()){
		setNextState("Menu");
		setFinished(true);

	}
}
void IntroState::render() {
	ofSetBackgroundColor(230, 230, 250);
    ofColor(ofColor::black);
	ofDrawBitmapString("Game Instructions: ",(ofGetWidth()/2) - 50 ,(ofGetHeight()/2) + 25);
	ofDrawBitmapString("-> Press 'e' when the player is in front of the counter to pickup ingredients",(ofGetWidth()/2) - 300 ,(ofGetHeight()/2) + 45);
	ofDrawBitmapString("-> Press 's' to serve the clients",(ofGetWidth()/2) - 300 ,(ofGetHeight()/2) + 60);
	ofDrawBitmapString("-> Press 'u' to undo the last ingredient",(ofGetWidth()/2) - 300 ,(ofGetHeight()/2) + 75);
	ofDrawBitmapString("-> Use '<-' (Left Arrow) or '->' (Right Arrow) to move the player",(ofGetWidth()/2) - 300 ,(ofGetHeight()/2) + 90);
	ofDrawBitmapString("-> Use 'p' to activate Patience Power Up",(ofGetWidth()/2) - 300 ,(ofGetHeight()/2) + 105);
	startButton->render();
}

void IntroState::keyPressed(int key){
	
}

void IntroState::mousePressed(int x, int y, int button){
	startButton->mousePressed(x, y);
}

void IntroState::reset(){
	setFinished(false);
	setNextState("");
	startButton->reset();
}