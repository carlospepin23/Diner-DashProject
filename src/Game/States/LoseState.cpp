#include "GameState.h"

LoseState::LoseState() {
	string text = "Go to Menu";
	startButton = new Button(ofGetWidth()/2 - text.length()*8, ofGetHeight()/2 - text.length()*8, 64, 50, text);
}
void LoseState::tick() {
	startButton->tick();
	if(startButton->wasPressed()){
		setNextState("Menu");
		setFinished(true);

	}
}
void LoseState::render() {
    ofDrawBitmapString("Game Over",(ofGetWidth()/2) - 45,(ofGetHeight()/2) + 25);
	startButton->render();
}

void LoseState::keyPressed(int key){
	
}

void LoseState::mousePressed(int x, int y, int button){
	startButton->mousePressed(x, y);
}

void LoseState::reset(){
	setFinished(false);
	setNextState("");
	startButton->reset();
}