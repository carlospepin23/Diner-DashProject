#pragma once

#include "State.h"
#include "Button.h"

class IntroState : public State {
private:
	ofImage img1;
	Button *startButton;

public:
	IntroState();
	void tick();
	void render();
	void keyPressed(int key);
	void mousePressed(int x, int y, int button);
	void reset();
};