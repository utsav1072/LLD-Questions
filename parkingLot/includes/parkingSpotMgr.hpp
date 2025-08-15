#pragma once
#include <mutex>
#include "parkingSpot.hpp"
#include "miniSpot.cpp"
#include "compactSpot.cpp"
#include "largeSpot.cpp"

class ParkingSpotMgr {
    ParkingSpotMgr(){};
    static ParkingSpotMgr* parkingSpotMgrInstance;
    static mutex mtx;
    vector<pair<int, ParkingSpot*>> freeSpots;
    unordered_map<int, ParkingSpot*> parkingSpots;
public:
    static ParkingSpotMgr* getParkingSpotMgr();
    ParkingSpot* getFreeSpots();
    unordered_map<int, ParkingSpot*> getParkingSpots();
    void freeUpSpots(ParkingSpot* pParkingSpot);
    void addParkingSpot();
};