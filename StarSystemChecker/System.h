/*
 * System.h
 *
 *  Created on: Feb 28, 2018
 *      Author: tstephen
 */

#ifndef SYSTEM_H_
#define SYSTEM_H_

#include "Object.h"

class System {
public:
	System();
	virtual ~System();

	void addObject(Object * o) { m_objects.push_back(o); }
	Object * getObject(int id) const { return m_objects[id]; }
	Object * getObject(std::string name) const;

	void printData() const;

private:
	// List of objects in the system.  Entry [0] should always be the star
	ObjectPtrList m_objects;
};

#endif /* SYSTEM_H_ */
