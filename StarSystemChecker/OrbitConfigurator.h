/*
 * OrbitConfigurator.h
 *
 *  Created on: Mar 1, 2018
 *      Author: tstephen
 */

#ifndef ORBITCONFIGURATOR_H_
#define ORBITCONFIGURATOR_H_

#include "System.h"

/**
 * @brief Class to set up simple orbit data for system
 *
 * This class takes the simplified input information and
 * determines initial positions and velocities for the
 * system.
 *
 * It assumes circular orbits, random starting orbital angles
 * and no orbital inclination in its default operation.
 */
class OrbitConfigurator {
public:
	OrbitConfigurator();
	virtual ~OrbitConfigurator();

	void simpleSetup(System &s);
};

#endif /* ORBITCONFIGURATOR_H_ */
