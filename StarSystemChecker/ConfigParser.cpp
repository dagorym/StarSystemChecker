/*
 * ConfigParser.cpp
 *
 *  Created on: Feb 28, 2018
 *      Author: tstephen
 */

#include <fstream>
#include <sstream>
#include <cstdlib>


#include "ConfigParser.h"

ConfigParser::ConfigParser(System *s): m_system(s) {

}

ConfigParser::~ConfigParser() {
	// TODO Auto-generated destructor stub
}

void ConfigParser::loadConfig(std::string file){
	const char delim = ','; // delimiter is a comma
	//@todo Add error checking

	std::ifstream inFile(file.c_str());
	std::string line,entry;
	std::vector<std::string> data;
	while (!inFile.eof()){
		// read a line
		getline(inFile,line);
		// split up the entries
		std::istringstream iss(line);
		while (std::getline(iss,entry,delim)){
			data.push_back(entry);
		}
		Object *o = new Object;
		o->setName(data[0]);
		o->setMass(std::atof(data[1].c_str()));
		o->setSemiMajor(std::atof(data[2].c_str()));
		if (data.size()>3){
			o->setEcentricity(std::atof(data[3].c_str()));
		}
		m_system->addObject(o);
		data.clear();
	}

}
