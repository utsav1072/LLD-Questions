#include "riderMgr.hpp"
RiderMgr* RiderMgr::riderMgrInstance = nullptr;
mutex RiderMgr::mtx;

RiderMgr* RiderMgr::getRiderMgr(){
    if(riderMgrInstance == nullptr){
        mtx.lock();
        if(riderMgrInstance == nullptr){
            riderMgrInstance = new RiderMgr();
        }
        mtx.unlock();
    }
    return riderMgrInstance;
}

Rider* RiderMgr::getRider(string pName){
    return ridersMap[pName];
}

void RiderMgr::addRider(string pName, Rider* pRider){
    ridersMap[pName] = pRider;
}