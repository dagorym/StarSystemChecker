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

Point::~Point() {
}

double Point::getDistance( Point p ) const{
	double dx = m_x - p.getX();
	double dy = m_y - p.getY();
	double dz = m_z - p.getZ();
	return sqrt (dx*dx + dy*dy + dz*dz);
}
