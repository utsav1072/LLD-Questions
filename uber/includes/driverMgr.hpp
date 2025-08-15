#pragma once

#include "driver.hpp"
#include <mutex>

class DriverMgr {
    DriverMgr(){};
    static DriverMgr* driverMgrInstance;
    static mutex mtx;
    unordered_map<string, Driver*> driverMap;
public:
    static DriverMgr* getDriverMgr();
    Driver* getDriver(string pName);
    void addDriver(string pName, Driver* pDriver);
    unordered_map<string, Driver*> getDriverMap();
};