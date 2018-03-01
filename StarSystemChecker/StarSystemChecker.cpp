/*
 * StarSystemChecker.cpp
 *
 *  Created on: Feb 28, 2018
 *      Author: Tom Stephens
 */


#include "ConfigParser.h"
#include "OrbitConfigurator.h"

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

	return 0;
}


