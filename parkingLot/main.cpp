#include "includes/ParkingLotService.hpp"
#include "includes/parkingSpot.hpp"
#include "includes/parkingSpotMgr.hpp"

using namespace std;

int main() {
    // Get ParkingLotService instance
    ParkingLotService* parkingLot = ParkingLotService::getParkingLotService();

    // Create 10 parking spots in ParkingSpotMgr
    ParkingSpotMgr* spotMgr = ParkingSpotMgr::getParkingSpotMgr();
    spotMgr->addParkingSpot();

    // Simulate vehicle entries
    cout << "---- Vehicle Entry ----" << endl;
    Vehicle* tempCar = parkingLot->vehicleEntry("KA01AB1234", VehicleType::Car);
    Vehicle* tempBike = parkingLot->vehicleEntry("KA02XY5678", VehicleType::Bike);
    Vehicle* tempTruck = parkingLot->vehicleEntry("KA03PQ9876", VehicleType::Truck);

    // Simulate vehicle exits
    cout << "\n---- Vehicle Exit ----" << endl;
    parkingLot->vechicleExit(tempCar);
    parkingLot->vechicleExit(tempBike);
    parkingLot->vechicleExit(tempTruck);

    return 0;
}
