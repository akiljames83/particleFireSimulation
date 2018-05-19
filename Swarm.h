#ifndef SWARM_H_
#define SWARM_H_

#include "Particle.h"

namespace sdlrefact {

class Swarm {
public:
	const static int NPARTICLES = 7000;
private:
	Particle* m_pParticles; // since its const and after the pointer decleration, it cant point at anything else
	int lastTime;

public:
	Swarm();
	virtual ~Swarm();
	const Particle* const getParticles() {return m_pParticles; }; // particle or particle location cant be changed with const delceration
	void update(int elapsed);

};



}; /*SDLREFACT*/




#endif