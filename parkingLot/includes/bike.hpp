#include "vehicle.hpp"

class Bike : public Vehicle {
public:
    Bike(string pLicensePlate, TimeStamp* pTimeStamp) : Vehicle(pLicensePlate, pTimeStamp) {}
    VehicleType getType(){
        return VehicleType::Bike;
    }
};