#ifndef SCREEN_H_
#define SCREEN_H_

#include <iostream>
#include <math.h>
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Swarm.h"
//#include "Particle.h"
using namespace std;

namespace sdlrefact {

class Screen {
public:
	const static int SCREEN_WIDTH = 800;
	const static int SCREEN_HEIGHT = 600;

private:
	SDL_Window *m_window; //m_ for member variables, to distinguish from instance variables
	SDL_Renderer* m_renderer;
	SDL_Texture* m_texture;
	Uint32* m_buffer1;
	Uint32* m_buffer2;

public:
	Screen();
	bool init(); // false if it fails, true otherwise
	void close(); // de-allocation code
	bool processEvents();
	void update();
	void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
	void clear();
	void boxBlur();


};




} /*sdlrefact namespace*/

#endif /*SCREEN_H_*/