#include "vehicle.hpp"

class Car : public Vehicle {
public:
    Car(string pLicensePlate, TimeStamp* pTimeStamp) : Vehicle(pLicensePlate, pTimeStamp) {}
    VehicleType getType(){
        return VehicleType::Car;
    }
};