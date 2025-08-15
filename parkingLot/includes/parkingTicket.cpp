#include "parkingTicket.hpp"

ParkingTicket::ParkingTicket(Vehicle* pVehicle, ParkingSpot* pParkingSpot, TimeStamp* pEntryTime) : 
    vehicle(pVehicle), parkingSpot(pParkingSpot), entryTime(pEntryTime)
{}

void ParkingTicket::printParkingTicket(){
    cout << "Vehicle Number : " << vehicle->getLicencePlate() << endl;
    cout << "Entry Time : " << vehicle->getEntryTime() << endl;
    cout << "Alloted Parking spot : " << parkingSpot->getId() << endl;
}

ParkingSpot* ParkingTicket::getParkingSpot(){
    return parkingSpot;
}
