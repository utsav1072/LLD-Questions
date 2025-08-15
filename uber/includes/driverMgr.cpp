#include "driverMgr.hpp"

DriverMgr* DriverMgr::driverMgrInstance = nullptr;
mutex DriverMgr::mtx;

DriverMgr* DriverMgr::getDriverMgr(){
    if(driverMgrInstance == nullptr){
        mtx.lock();
        if(driverMgrInstance == nullptr){
            driverMgrInstance = new DriverMgr();
        }
        mtx.unlock();
    }
    return driverMgrInstance;
}

void DriverMgr::addDriver(string pName, Driver* pDriver){
    driverMap[pName] = pDriver;
}

Driver* DriverMgr::getDriver(string pName){
    return driverMap[pName];
}

unordered_map<string, Driver*> DriverMgr::getDriverMap(){
    return driverMap;
}