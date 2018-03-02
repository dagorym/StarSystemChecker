/*
 * OrbitConfigurator.cpp
 *
 *  Created on: Mar 1, 2018
 *      Author: tstephen
 */

#include <cstdlib>
#include <cmath>
#include <ctime>

#include "OrbitConfigurator.h"
#include "constants.h"


OrbitConfigurator::OrbitConfigurator() {
	std::srand(time(NULL));  // need to set the random number generator for the orbital angles

}

OrbitConfigurator::~OrbitConfigurator() {
	// TODO Auto-generated destructor stub
}

void OrbitConfigurator::simpleSetup(System &s){
	const unsigned int count = s.getNumObjects();

	double starMass = s.getObject(0)->getMass();
	for (unsigned int i = 1; i < count; i++){
		Object *o = s.getObject(i);
		double sm = o->getSemiMajor();
		// determine random orbital angle and compute starting position
		int angle = rand() % 360;
		double x = sm * std::cos(angle);
		double y = sm * std::sin(angle);
		o->setPosition(x,y,0.);
		// determine circular orbital speed based on stellar mass and semi-major axis
		// Note:  This should really include all the mass inside the orbit, not just the star
		double oSpeed = sqrt(G*starMass/sm);
		//now compute x & velocities based on angle
		double vx = oSpeed * std::sin(angle);
		double vy = -oSpeed * std::cos(angle);
		o->setVelocity(vx,vy,0.);
	}

}
