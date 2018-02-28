/*
 * Object.h
 *
 *  Created on: Feb 28, 2018
 *      Author: tstephen
 */

#ifndef OBJECT_H_
#define OBJECT_H_

#include <vector>
#include <string>

#include "Point.h"

/**
 * @brief This class holds the data for a single astronomical object
 *
 * @author Tom Stephens
 * @date Created: Feb 28, 2018
 */
class Object {
public:
	Object();
	Object(std::string name, double mass, double sm, double e=0);
	virtual ~Object();

	std::string getName() const { return m_name; }
	double getSemiMajor() const { return m_semiMajor; }
	double getMass() const { return m_mass; }
	double getEccentricity() const { return m_eccentricity; }
	Point getPosition() const {return m_position; }

	void setName(std::string n) { m_name = n; }
	void setSemiMajor(double s) { m_semiMajor = s; }
	void setMass(double m) { m_mass = m; }
	void setEcentricity(double e) { m_eccentricity = e; }
	void setPosition(Point p);
	void setPosition(double x, double y, double z);

	void printData() const;


private:
	// The name of the object
	std::string m_name;
	// mass of the object in kilograms
	double m_mass;
	// Size of the orbital semi-major axis in meters
	double m_semiMajor;
	// orbital eccentricity
	double m_eccentricity;
	// Object's position
	Point m_position;
};

typedef std::vector<Object *> ObjectPtrList;

#endif /* OBJECT_H_ */
