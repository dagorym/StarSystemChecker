/*
 * Integrator.h
 *
 *  Created on: Mar 1, 2018
 *      Author: tstephen
 */

#ifndef INTEGRATOR_H_
#define INTEGRATOR_H_

#include "System.h"

/**
 * @brief Class to do n-body calculations
 *
 * This class will do the actual nbody caluculations to
 * move the objects in the system around.
 *
 * @author Tom Stephens
 * @date March 1, 2018
 */
class Integrator {
public:
	Integrator();
	Integrator(double timestep);
	virtual ~Integrator();

	void setTimeStep(int t) { m_timeStep = 300; }
	double getTimeStep() const { return m_timeStep; }

	/**
	 * @brief public method to advance the system a single timestep
	 *
	 * This method performs a single time step, computing the changes for
	 * each object and applying those changes.  It only updates the positions
	 * and velocities of the objects.
	 *
	 * It returns zero upon a successful integration.
	 *
	 * @params s A reference to the System object containing the objects to integrate
	 *
	 * @author Tom Stephens
	 * @date Created: March 1, 2018
	 */
	int Integrate(System &s);

private:
	// size of timestep to take during a single integration, in seconds. Default is 300.
	double m_timeStep;
};

#endif /* INTEGRATOR_H_ */
