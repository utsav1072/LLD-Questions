#pragma once
#include <iostream>
#include <vector>
#include "TimeStamp.hpp"
#include <utility>
#include <unordered_map>
using namespace std;

static int parkingSpotId = 1;

enum class VehicleType {
    Bike,
    Car, 
    Truck,
};
