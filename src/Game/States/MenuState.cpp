#include "MenuState.h"

MenuState::MenuState() {
	string text = "Start";
	startButton = new Button(ofGetWidth()/2 - text.length()*8, ofGetHeight()/2 - text.length()*11, 64, 50, "Start");

	// string text2 = "Game Instructions";
	// introButton = new Button(ofGetWidth()/2 - text2.length()*8, ofGetHeight()/2 - text2.length()*11, 64, 50, "Game Instructions");
}
void MenuState::tick() {
	startButton->tick();
	// introButton->tick();
	if(startButton->wasPressed()){
		setNextState("Game");
		setFinished(true);

	}
	// else if(introButton->wasPressed()){
	// 	setNextState("Intro");
	// 	setFinished(true);

	// }
}
void MenuState::render() {
	ofSetBackgroundColor(230, 230, 250);
	startButton->render();
	// introButton->render();
}

void MenuState::keyPressed(int key){
	
}

void MenuState::mousePressed(int x, int y, int button){
	startButton->mousePressed(x, y);
	// introButton->mousePressed(x, y);
}

void MenuState::reset(){
	setFinished(false);
	setNextState("");
	startButton->reset();
	// introButton->reset();
}