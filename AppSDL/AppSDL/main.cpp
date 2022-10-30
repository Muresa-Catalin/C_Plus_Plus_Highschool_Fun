#include "SDL.h"
#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <time.h>
#include "Screen.h"
#include "Particle.h"
#include "Swarm.h"

using namespace std;

int main(int argc, char *argv[]){

	///// SDL SETUP /////

	//Seeding teh rand numbers so that they change every time
	srand(time(NULL));

	Screen screen;

	if (screen.init() == false) {
		cout << "Error, Sdl not working lul\n";
	}

	Swarm swarm;
	

	////// GAME SETUP //////
	
	while (true) {
		//Update particles
		//Draw particles
		int elapsed = SDL_GetTicks();

		
		swarm.update(elapsed);

		unsigned char green = (unsigned char)((1 + sin(elapsed * 0.0001)) * 128);
		unsigned char red = (unsigned char)((1 + sin(elapsed * 0.0002)) * 128);
		unsigned char blue = (unsigned char)((1 + sin(elapsed * 0.0003)) * 128);

		const Particle * const pParticles = swarm.getParticles();

		for (int i = 0; i < Swarm::NPARTICLES; i++) {
			Particle particle = pParticles[i];

			int x = (particle.m_x + 1) * Screen::SCREEN_WIDTH / 2;
			int y = particle.m_y * Screen::SCREEN_WIDTH / 2 + Screen::SCREEN_HEIGHT / 2;

			screen.setPixel(x, y, red, green, blue);
		}

		screen.boxBlur();

		//Draw the screen

		screen.update();

		//Check for messages
		if (screen.proccesEvent() == false) {
			break;
		}
	}


	///// QUITTING SDL /////
	screen.close();

	//system("pause");
	return 0;
}