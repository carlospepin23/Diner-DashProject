#include "MenuState.h"

MenuState::MenuState() {
	menu.load("images/title.jpg");
	string text = "Start";
	startButton = new Button(ofGetWidth()/2 - text.length()*8, ofGetHeight()/2 - text.length()*11, 64, 50, text);
}
void MenuState::tick() {
	startButton->tick();
	if(startButton->wasPressed()){
		setNextState("Game");
		setFinished(true);

	}

}
void MenuState::render() {
	ofSetColor(ofColor::white);
	menu.draw(0,0, ofGetWidth(), ofGetHeight());
	startButton->render();
}

void MenuState::keyPressed(int key){
	
}

void MenuState::mousePressed(int x, int y, int button){
	startButton->mousePressed(x, y);
}

void MenuState::reset(){
	setFinished(false);
	setNextState("");
	startButton->reset();
}