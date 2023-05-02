#pragma once
#include<SDL/SDL.h>
#include<GL/eglew.h>
#include"Sprite.h"
#include<ctime>
#include<algorithm>
#include<vector>
enum class GameState {
	PLAY, EXIT
};

class MainGame {
private:
	int width;
	int height;
	SDL_Window* window;
	void init();
	vector<Sprite> sprites;
	void processInput();
	void addsquare();

public:
	MainGame();
	~MainGame();
	GameState gameState;
	time_t t;
	void run();
	void draw();
	void update();
};