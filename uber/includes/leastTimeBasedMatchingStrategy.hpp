#pragma once
#include "driverMatchingStrategy.hpp"

class LeastTimeBasedMatchingStrategy : public DriverMatchingStrategy {
public:
	Driver* matchDriver(TripMetaData* pMetaData) {
		DriverMgr* driverMgr = DriverMgr::getDriverMgr();

		if ((driverMgr->getDriverMap()).size() == 0) {
			cout << "No drivers!" << endl;
		}
		cout << "Using quadtree to see nearest cabs, using driver manager to get details of drivers and send notifications" << endl;
		Driver* driver = ((driverMgr->getDriverMap()).begin())->second;
		cout << "Setting " << driver->getDriverName() << " as driver" << endl;
		pMetaData->setDriverRating(driver->getDriverRating());
		return driver;
	}
};