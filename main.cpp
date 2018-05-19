#include "Screen.h"

using namespace sdlrefact;

//Color Screen Refact Project !!!!!!

int main() {

	srand(time(NULL)); // changes random sequence each time from stdlib library, initialized with a number (time) from time.h library

	Screen screen;

	if(screen.init() == false) { // initial checking
		cout << "Error initializing SDL." << endl;
	}

	Swarm swarm;

	int s_width = Screen::SCREEN_WIDTH/2;
	int s_height = Screen::SCREEN_HEIGHT/2;

	while(true) {
		int elapsed = SDL_GetTicks();

		//screen.clear(); No longer clearing screen, gonna blur it
		swarm.update(elapsed); 

		unsigned char green = (unsigned char)((1+cos(elapsed*0.0002))*128);
		unsigned char red = (unsigned char)((1+cos(elapsed*0.0003 + 0.8))*128);
		unsigned char blue = (unsigned char)((1+sin(elapsed*0.0004 + 1.57))*128);

		// Placing particles on the screen
		const Particle* const pParticles = swarm.getParticles();//pointer to the const position of const value of first el in array of particles
		for(int i=0;i<Swarm::NPARTICLES;i++){
			Particle particle = pParticles[i];

			int x = (particle.m_x + 1)* s_width;
			int y = particle.m_y * s_width + s_height;

			screen.setPixel(x,y,red,green,blue);
		}
		// blur screen with blur algorithm
		screen.boxBlur();

		// draw the screen
		screen.update();


		if(!screen.processEvents()){
			break;
		}
	}

	screen.close();
	
	return 0;
}