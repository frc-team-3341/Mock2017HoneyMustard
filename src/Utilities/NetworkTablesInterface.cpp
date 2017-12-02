/*
 * NetworkTablesInterface.cpp
 *
 *  Created on: Jan 17, 2017
 *      Author: Dhruti
 */

#include "NetworkTablesInterface.h"


/*NetworkTablesInterface::NetworkTablesInterface() {
	// TODO Auto-generated constructor stub

}

NetworkTablesInterface::~NetworkTablesInterface() {
	// TODO Auto-generated destructor stub
}*/


double NetworkTablesInterface::getPosition()
{
	return NetworkTable::GetTable("cv")->GetNumber("type", -1.0);
}

double NetworkTablesInterface::getAzimuth()
{
	return NetworkTable::GetTable("cv")->GetNumber("azimuth", 0);

}
