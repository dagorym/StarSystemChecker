/*
 * OrbitConfigurator.cpp
 *
 *  Created on: Mar 1, 2018
 *      Author: tstephen
 */

#include <cstdlib>
#include <ctime>

#include "OrbitConfigurator.h"

OrbitConfigurator::OrbitConfigurator() {
	std::srand(time(NULL));  // need to set the random number generator for the orbital angles

}

OrbitConfigurator::~OrbitConfigurator() {
	// TODO Auto-generated destructor stub
}

void OrbitConfigurator::simpleSetup(System &s){


}
