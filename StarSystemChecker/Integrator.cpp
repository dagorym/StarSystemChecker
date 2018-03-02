/*
 * Integrator.cpp
 *
 *  Created on: Mar 1, 2018
 *      Author: tstephen
 */

#include "Integrator.h"
#include "constants.h"

Integrator::Integrator():m_timeStep(300) {
	// TODO Auto-generated constructor stub

}

Integrator::Integrator(double t) {
	m_timeStep = t;

}

Integrator::~Integrator() {
	// TODO Auto-generated destructor stub
}

int Integrator::integrate(System &s){
	//@todo this would all be easier as loops over the position and velocity components
	Object *o1,*o2;
	PointList vList;
	double tG = G * m_timeStep;
	// store current velocities
	for (unsigned int i = 0; i < s.getNumObjects(); i++){
		vList.push_back(s.getObject(i)->getVelocity());
	}
	// loop over all the objects (object a)
	for (unsigned int i = 0; i < s.getNumObjects(); i++){
		o1 = s.getObject(i);
		Point p1 = o1->getPosition();

		//loop over all the remaining objects (object b)
		for (unsigned int j = i+1; j < s.getNumObjects(); j++){
			o2 = s.getObject(j);
			Point p2 = o2->getPosition();
			double angle = atan2(p2.getY()-p1.getY(),p2.getX()-p1.getX());
			double d = p2.getDistance(p1);
			double aFactor = tG/(d*d);
			double f1 = aFactor * o2->getMass();
			double f2 = aFactor * o1->getMass();
			vList[i].addX(f1*cos(angle));
			vList[j].addX(-f2*cos(angle));
			vList[i].addY(f1*sin(angle));
			vList[j].addY(-f2*sin(angle));

		}
		o1->setVelocity(vList[i]);
	}
	// loop over all the objects
	for (unsigned int i = 0; i < s.getNumObjects(); i++){
		//update velocities & positions
		o1=s.getObject(i);
		Point pos = o1->getPosition();
		Point vel = o1->getVelocity();
		pos.addX(vel.getX() * m_timeStep);
		pos.addY(vel.getY() * m_timeStep);
//		pos.addZ(vel.getZ() * m_timeStep);
		o1->setPosition(pos);
	}

	return 0;
}
