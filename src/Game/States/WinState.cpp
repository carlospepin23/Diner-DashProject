#include "GameState.h"

WinState::WinState() {
	string text = "Go to Menu";
	startButton = new Button(ofGetWidth()/2 - text.length()*8, ofGetHeight()/2 - text.length()*11, 64, 50, text);
}
void WinState::tick() {
	startButton->tick();
	if(startButton->wasPressed()){
		setNextState("Menu");
		setFinished(true);

	}
}
void WinState::render() {
	// ofSetBackgroundColor(0,0,0);
    // ofColor(ofColor::white);
    ofDrawBitmapString("You Won!",(ofGetWidth()/2),(ofGetHeight()/2) + 25);
	startButton->render();
}

void WinState::keyPressed(int key){
	
}

void WinState::mousePressed(int x, int y, int button){
	startButton->mousePressed(x, y);
}

void WinState::reset(){
	setFinished(false);
	setNextState("");
	startButton->reset();
}