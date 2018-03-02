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
			// calculate mutual delta-v's on a & B
			// First we need the forces (F=GMM/r^2)
			double dx = p2.getX() - p1.getX();
			double fx = tG/(dx*dx);
			double dy = p2.getY() - p1.getY();
			double fy = tG/(dy*dy);
//			double dz = p2.getZ() - p1.getZ();
//			double fz = tG/(dz*dz);
			// add to object's velocity
			double dv1 = fx*o2->getMass()*sgn(dx);
			double dv2 = fx*o1->getMass()*-sgn(dx);
			vList[i].addX(dv1);
			vList[j].addX(dv2);
			dv1 = fy*o2->getMass()*sgn(dy);
			dv2 = fy*o1->getMass()*-sgn(dy);
			vList[i].addY(dv1);
			vList[j].addY(dv2);
//			dv1 = fz*o2->getMass()*sgn(dz);
//			dv2 = fz*o1->getMass()*-sgn(dz);
//			vList[i].addZ(dv1);
//			vList[j].addZ(dv2);
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
