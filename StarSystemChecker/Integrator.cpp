/*
 * Integrator.cpp
 *
 *  Created on: Mar 1, 2018
 *      Author: tstephen
 */

#include "Integrator.h"

Integrator::Integrator():m_timeStep(300) {
	// TODO Auto-generated constructor stub

}

Integrator::Integrator(double t) {
	m_timeStep = t;

}

Integrator::~Integrator() {
	// TODO Auto-generated destructor stub
}

int Integrator::Integrate(System &s){

	return 0;
}
