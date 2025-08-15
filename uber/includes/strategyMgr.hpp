#pragma once
#include "defaultPricingStrategy.hpp"
#include "ratingBasedPricingStrategy.hpp"
#include "leastTimeBasedMatchingStrategy.hpp"
#include "common.hpp"
#include <mutex>

class StrategyMgr {
    static StrategyMgr* strategyMgrInstance;
    static mutex mtx;
public:
    static StrategyMgr* getStrategyMgr();
    PricingStrategy* determinePricingStrategy(TripMetaData* metaData);
    DriverMatchingStrategy* determineDriverMatchingStrategy(TripMetaData* metaData);
};