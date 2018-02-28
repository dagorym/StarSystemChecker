/*
 * ConfigParser.h
 *
 *  Created on: Feb 28, 2018
 *      Author: tstephen
 */

#ifndef CONFIGPARSER_H_
#define CONFIGPARSER_H_

#include "System.h"

class ConfigParser {
public:
	ConfigParser(System *s);
	virtual ~ConfigParser();

	void loadConfig(std::string file);

private:
	System *m_system;
};

#endif /* CONFIGPARSER_H_ */
