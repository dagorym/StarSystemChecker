/*
 * Point.cpp
 *
 *  Created on: Feb 28, 2018
 *      Author: tstephen
 */

#include "Point.h"
#include <cmath>

Point::Point() {
	m_x = 0;
	m_y = 0;
	m_z = 0;
}

Point::Point (const Point &p){
	m_x = p.m_x;
	m_y = p.m_y;
	m_z = p.m_z;
}

Point & Point::operator = (const Point &p){
	if (this != &p){
		m_x = p.m_x;
		m_y = p.m_y;
		m_z = p.m_z;
	}
	return *this;
}


Point::~Point() {
}

double Point::getDistance( Point p ) const{
	double dx = m_x - p.getX();
	double dy = m_y - p.getY();
	double dz = m_z - p.getZ();
	return sqrt (dx*dx + dy*dy + dz*dz);
}
