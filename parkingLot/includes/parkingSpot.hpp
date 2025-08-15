#pragma once
#include "common.hpp"
#include "vehicle.hpp"

class ParkingSpot {
protected:
    int id;
    bool avail;
    Vehicle* vehicle;
public:
    ParkingSpot() : avail(true), vehicle(nullptr) {
        id = parkingSpotId;
        parkingSpotId++;
    }
    int getId(){
        return id;
    }
    void park(Vehicle* vehicle){
        avail = false;
        this->vehicle = vehicle;
    }
    void unpark(){
        avail = true;
        vehicle = nullptr;
    }
    virtual double cost() = 0;
};