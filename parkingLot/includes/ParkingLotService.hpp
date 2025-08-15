#pragma once
#include "vehicle.hpp"
#include "parkingSpotMgr.hpp"
#include "parkingTicket.hpp"
#include "car.hpp"
#include "truck.hpp"
#include "Bike.hpp"
#include "parkingSpotMgr.hpp"

class ParkingLotService {
    ParkingLotService(){}
    static ParkingLotService* parkingLotServiceInstance;
    static mutex mtx;
    unordered_map<Vehicle*, ParkingTicket*> parkedVehicles;
public:
    static ParkingLotService* getParkingLotService();
    Vehicle* vehicleEntry(string pLincesePlate, VehicleType pType);
    ParkingTicket* assignSpotAndPark(Vehicle* pVehicle);
    void vechicleExit(Vehicle* pVehicle);
};