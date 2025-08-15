#include "parkingSpotMgr.hpp"
ParkingSpotMgr* ParkingSpotMgr::parkingSpotMgrInstance = nullptr;
mutex ParkingSpotMgr::mtx;

ParkingSpotMgr* ParkingSpotMgr::getParkingSpotMgr(){
    if(parkingSpotMgrInstance == nullptr){
        mtx.lock();
        if(parkingSpotMgrInstance == nullptr){
            parkingSpotMgrInstance = new ParkingSpotMgr();
        }
        mtx.unlock();
    }
    return parkingSpotMgrInstance;
}

void ParkingSpotMgr::freeUpSpots(ParkingSpot* pParkingSpot){
    freeSpots.push_back({pParkingSpot->getId(), pParkingSpot});
}


unordered_map<int, ParkingSpot*> ParkingSpotMgr::getParkingSpots(){
    return parkingSpots;
}
ParkingSpot* ParkingSpotMgr::getFreeSpots(){
    ParkingSpot* freeSpot = freeSpots[0].second;
    freeSpots.erase(freeSpots.begin());
    return freeSpot;
}

void ParkingSpotMgr::addParkingSpot(){
    for(int i = 1; i <= 10 ; i++){
        ParkingSpot* nMiniSpot = new MiniSpot();
        ParkingSpot* nCompactSpot = new CompactSpot();
        ParkingSpot* nLargeSpot = new LargeSpot();
        freeSpots.push_back({nMiniSpot->getId() ,nMiniSpot});
        freeSpots.push_back({nCompactSpot->getId() ,nCompactSpot});
        freeSpots.push_back({nLargeSpot->getId() ,nLargeSpot});
    }
    return;
}