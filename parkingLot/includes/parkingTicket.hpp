#include "common.hpp"
#include "vehicle.hpp"
#include "parkingSpot.hpp"

class ParkingTicket {
    TimeStamp* entryTime;
    Vehicle* vehicle;
    ParkingSpot* parkingSpot;
public:
    ParkingTicket(Vehicle* pVehicle, ParkingSpot* pParkingSpot, TimeStamp* pEntryTime);
    void printParkingTicket(); 
    ParkingSpot* getParkingSpot();
};