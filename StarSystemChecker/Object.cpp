/*
 * Object.cpp
 *
 *  Created on: Feb 28, 2018
 *      Author: tstephen
 */

#include <iostream>

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
}

void Object::setPosition(Point p){
	m_position = p;
}

void Object::setPosition(double x, double y, double z){
	m_position.setX(x);
	m_position.setY(y);
	m_position.setZ(z);
}

void Object::printData() const{
	std::cout << "Name: " << m_name << std::endl;
	std::cout << "Mass: " << m_mass << std::endl;
	std::cout << "Semi-major Axis: " << m_semiMajor << std::endl;
	std::cout << "Orbital Distance: " << m_position.getDistance(Point(0,0,0)) << std::endl;
	std::cout << "Eccentricity: " << m_eccentricity << std::endl;
}
