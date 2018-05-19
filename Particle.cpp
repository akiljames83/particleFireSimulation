#include "Particle.h"
namespace sdlrefact {

Particle::Particle() : m_x(0), m_y(0)
{ // Now we are initalizing the position of the particles to the center of the screen
	init();
}

Particle::~Particle(){

}
void Particle::init() {
	m_x = 0;
	m_y = 0;
	m_direction = 2* M_PI * ((double)rand()/RAND_MAX);
	m_speed = 0.032 * (double)rand()/RAND_MAX;
	m_speed *= m_speed;
}
void Particle::update(int interval) { // called in swarm update file

	m_direction += interval*0.0002; // i like * 0.0004
	double xspeed = m_speed * cos(m_direction);
	double yspeed = m_speed * sin(m_direction);

	m_x += xspeed * interval;
	m_y += yspeed * interval;

	if(m_x < -1 || m_x > 1 || m_y < -1 || m_y > 1 ) {
		init();
	}

	if(rand() < RAND_MAX/100) {
		init();
	}

}

};