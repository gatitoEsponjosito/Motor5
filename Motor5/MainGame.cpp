#include"MainGame.h"
#include"Error.h"
#include<iostream>
#include<random>
MainGame::MainGame() {
	window = nullptr;
	width = 800;
	height = 600;
	gameState = GameState::PLAY;
}

MainGame::~MainGame() {

}

void MainGame::init() {
	t = clock();
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("Hola", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		width, height, SDL_WINDOW_OPENGL);

	if (window == nullptr) {
		fatalError("SDL NOT INITIALIZED");
	}
	SDL_GLContext glContext = SDL_GL_CreateContext(window);
	GLenum error = glewInit();
	if ( error != GLEW_OK ) {
		fatalError("GLEW NOT INITIALIZED");
	}
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	sprites.push_back(Sprite());
	sprites.push_back(Sprite());
}

void MainGame::draw() {
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	for (int i = 0; i < sprites.size(); i++){
		sprites[i].draw();
	}
	// si tengo elementos actualizados
	SDL_GL_SwapWindow(window);
}

void MainGame::processInput() {
	SDL_Event event;
	while (SDL_PollEvent(&event)){
		switch (event.type)
		{
		case SDL_QUIT:
			gameState = GameState::EXIT;
			break;
		case SDL_MOUSEMOTION:
			break;
		}
	}
	
}

void MainGame::addsquare(){
	time_t t2 = clock();
	int tiempoRecorrido = int(float(clock() - t) / CLOCKS_PER_SEC);
	cout << tiempoRecorrido << "\n";
	if (tiempoRecorrido == 5) {
		t = clock();
		sprites.push_back(Sprite());
		int i = sprites.size() - 1;
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_real_distribution<float> distrib(-1.0f, 1.0f);
		float x = distrib(gen);
		float y = distrib(gen);
		sprites[i].init(x, y, 0.3, 0.3);
	}
}

void MainGame::run() {
	init();
	sprites[0].init(1, 1, -0.3, -0.3);
	sprites[1].init(-0.5, -0.5,0.3, 0.3);
	update();
}

void MainGame::update() {
	while (gameState != GameState::EXIT){
		draw();
		addsquare();
		processInput();
	}
}