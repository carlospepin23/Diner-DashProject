#pragma once
#include "State.h"
#include "Button.h"
#include "Restaurant.h"

class GameState: public State{
    public: 
        GameState();
		void reset();
		void tick();
		void render();
		void keyPressed(int key);
		void mousePressed(int x, int y, int button);
		void keyReleased(int key);
	
	private:
		Restaurant *restaurant;
};

class WinState : public State{
	private:
		ofImage img1;
		Button *startButton;
	public:
		WinState();
		void tick();
		void render();
		void keyPressed(int key);
		void mousePressed(int x, int y, int button);
		void reset();
};

class LoseState : public State{
	private:
		ofImage img1;
		Button *startButton;
	public:
		LoseState();
		void tick();
		void render();
		void keyPressed(int key);
		void mousePressed(int x, int y, int button);
		void reset();
};