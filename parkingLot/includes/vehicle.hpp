#pragma once
#include "common.hpp"

class Vehicle {
protected:
    string licensePlate;
    TimeStamp* entryTime;
    VehicleType type;
public:
    Vehicle(string pLincesePlate, TimeStamp* pEntrytime) : licensePlate(pLincesePlate), entryTime(pEntrytime) {}
    string getLicencePlate(){
        return licensePlate;
    }
    TimeStamp* getEntryTime(){
        return entryTime;
    }
    virtual VehicleType getType() = 0;
    virtual ~Vehicle() {}
};