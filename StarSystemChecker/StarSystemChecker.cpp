/*
 * StarSystemChecker.cpp
 *
 *  Created on: Feb 28, 2018
 *      Author: Tom Stephens
 */

#include <iostream>

#include "ConfigParser.h"
#include "OrbitConfigurator.h"
#include "Integrator.h"

const int STEP_SIZE = 300; // five minutes
//const int NSTEPS = 20000; //about a week
const int NSTEPS = 105192; //one year in 5 minute increments

int main (int argc, char* argv[]){
	//read in system configuration
	//compute initial positions
	//integrate
		// occasionally print output
		// check for system collapse
	// generate report

	System m_system;

	ConfigParser cp(&m_system);
	cp.loadConfig("system_data.dat");

	OrbitConfigurator oc;
	oc.simpleSetup(m_system);

	m_system.printData();

	Integrator in(STEP_SIZE);
	for (int i = 0; i < NSTEPS; i++){
		in.integrate(m_system);
//		std::cout << i << " " << m_system.getObject(1)->getPosition().getX()
//				<< " " << m_system.getObject(1)->getPosition().getY()
//				<< " " << m_system.getObject(1)->getVelocity().getX()
//				<< " " << m_system.getObject(1)->getVelocity().getY() << std::endl;
	}

	m_system.printData();

	return 0;
}


