/*
 * NetworkTablesInterface.h
 *
 *  Created on: Jan 17, 2017
 *      Author: Dhruti
 */

#ifndef UTILITIES_NETWORKTABLESINTERFACE_H_
#define UTILITIES_NETWORKTABLESINTERFACE_H_

#include "NetworkTables/NetworkTable.h"

class NetworkTablesInterface {
public:
	//NetworkTablesInterface(); NOT REQUIRED
	//virtual ~NetworkTablesInterface(); NOT REQUIRED

	static double getPosition();
	static double getAzimuth();

};

#endif /* UTILITIES_NETWORKTABLESINTERFACE_H_ */
