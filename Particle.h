#ifndef PARTICLE_H_
#define PARTICLE_H_

#include <math.h>
#include <stdlib.h>
namespace sdlrefact {

class Particle { // lil tip difference between class and a struct, class members are private default, struct are public default
public: 
	double m_x;
	double m_y;
	// switching from cartesian to polar coordinate system so no speed necessary for x and y
	double m_speed;
	double m_direction; // ranges from 0 to 360;

public:
	Particle();
	virtual ~Particle(); // Review what virtual is for thooo
	void update(int interval);
	
private:
	void init();



};



}; /*SDLREFACT*/




#endif