/*
 * System.cpp
 *
 *  Created on: Feb 28, 2018
 *      Author: tstephen
 */

#include <iostream>

#include "System.h"

System::System() {

}

System::~System() {
	for (ObjectPtrList::iterator itr = m_objects.begin();itr < m_objects.end();itr++){
		delete *itr;
	}
}

Object * System::getObject(std::string name) const {
	ObjectPtrList::const_iterator itr = m_objects.begin();
	while (itr < m_objects.end()){
		if (name == (*itr)->getName()){
			return *itr;
		}
		itr++;
	}
	return NULL;
}

void System::printData() const{
	for (ObjectPtrList::const_iterator itr = m_objects.begin();itr < m_objects.end();itr++){
		(*itr)->printData();
		std::cout << std::endl;
	}
}
