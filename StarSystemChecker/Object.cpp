/*
 * Object.cpp
 *
 *  Created on: Feb 28, 2018
 *      Author: tstephen
 */

#include "Object.h"

Object::Object() {
	m_name="Unnamed";
	m_mass = 0;
	m_semiMajor = 0;
	m_eccentricity = 0;
	// TODO Auto-generated constructor stub

}

Object::Object(std::string name, double mass, double sm, double e):
	m_name(name),m_mass(mass), m_semiMajor(sm), m_eccentricity(e){

}

Object::~Object() {
	// TODO Auto-generated destructor stub
}

