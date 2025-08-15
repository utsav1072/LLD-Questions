#pragma once

#include "rider.hpp"
#include <mutex>

class RiderMgr {
    RiderMgr(){}
    static RiderMgr* riderMgrInstance;
    static mutex mtx;
    unordered_map<string, Rider*> ridersMap;
public:
    static RiderMgr* getRiderMgr();
    Rider* getRider(string pName);
    void addRider(string pName, Rider* pRider);
    // unordered_map<string, Rider*> getRidersMap();
};