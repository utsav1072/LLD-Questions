#include "ParkingLotService.hpp"
ParkingLotService* ParkingLotService::parkingLotServiceInstance = nullptr;
mutex ParkingLotService::mtx;


ParkingLotService* ParkingLotService::getParkingLotService(){
    if(parkingLotServiceInstance == nullptr){
        mtx.lock();
        if(parkingLotServiceInstance == nullptr){
            parkingLotServiceInstance = new ParkingLotService();
        }
        mtx.unlock();
    }
    return parkingLotServiceInstance;
}

ParkingTicket* ParkingLotService::assignSpotAndPark(Vehicle* pVehicle){
    // can implement Parking Strategy i am just going with the first available spot
    ParkingSpotMgr* IParkingSpotMgr = ParkingSpotMgr::getParkingSpotMgr();
    ParkingSpot* parkingSpot = IParkingSpotMgr->getFreeSpots(); 
    parkingSpot->park(pVehicle);
    return new ParkingTicket(pVehicle, parkingSpot, pVehicle->getEntryTime());
}

Vehicle* ParkingLotService::vehicleEntry(string pLicensePlate, VehicleType pType){
    TimeStamp* time = new TimeStamp(1);
    Vehicle* nVehicle = nullptr;
    if(pType == VehicleType::Car)
    {
        nVehicle = new Car(pLicensePlate, time);
    }
    else if(pType == VehicleType::Bike)
    {
        nVehicle = new Bike(pLicensePlate, time);
    }
    else if(pType == VehicleType::Truck)
    {
        nVehicle = new Truck(pLicensePlate, time);
    }
    // only assign and park if parking is not full, i will implement this later.
    if(nVehicle != nullptr)
        parkedVehicles[nVehicle] = assignSpotAndPark(nVehicle);
    return nVehicle;
}

void ParkingLotService::vechicleExit(Vehicle* pVehicle){
    ParkingTicket* ticket = parkedVehicles[pVehicle];
    auto parkingSpot = ticket->getParkingSpot();
    double Cost = parkingSpot->cost();
    ticket->printParkingTicket();
    cout << "Please Pay : " << Cost << endl;
    cout << "Thank You For The Visit !\n";
    parkingSpot->unpark();
    delete pVehicle;
    ParkingSpotMgr* IParkingSpotMgr = ParkingSpotMgr::getParkingSpotMgr();
    IParkingSpotMgr->freeUpSpots(parkingSpot);
}