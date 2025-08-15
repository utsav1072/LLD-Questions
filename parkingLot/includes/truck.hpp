#include "vehicle.hpp"

class Truck : public Vehicle {
public:
    Truck(string pLicensePlate, TimeStamp* pTimeStamp) : Vehicle(pLicensePlate, pTimeStamp) {}
    VehicleType getType(){
        return VehicleType::Truck;
    }
};