#include "includes/tripMgr.hpp"

int main() {

	//---------------Creating Riders and Drivers--------------------------------
	Rider* utsavRider = new Rider("utsav", RATING::FIVE_STARS);
	Rider* AbhishekRider = new Rider("Abhishek", RATING::FIVE_STARS);
	RiderMgr* riderMgr = RiderMgr::getRiderMgr();
	riderMgr->addRider("utsav", utsavRider);
	riderMgr->addRider("Abhishek", AbhishekRider);

	Driver* yogitaDriver = new Driver("Yogita", RATING::THREE_STARS);
	Driver* riddhiDriver = new Driver("Riddhi", RATING::FOUR_STARS);
	DriverMgr* driverMgr = DriverMgr::getDriverMgr();
	driverMgr->addDriver("yogita", yogitaDriver);
	driverMgr->addDriver("riddhi", riddhiDriver);

	//These details in turn will be stored in database
	//-------------------------------------------------------------------------

	TripMgr* tripMgr = TripMgr::getTripMgr();


	cout << endl << "Creating Trip for utsav from location (10,10) to (30,30)" << endl;
	tripMgr->CreateTrip(utsavRider, new Location(10, 10), new Location(30, 30));

	cout << endl << "Creating Trip for Abhishek from location (200,200) to (500,500)" << endl;
	tripMgr->CreateTrip(AbhishekRider, new Location(200, 200), new Location(500, 500));


	//-------------------Display all the trips created--------------------------
	unordered_map<int, Trip*> tripsMap = tripMgr->getTripsMap();
	for (auto mapVal : tripsMap) {
		(mapVal.second)->displayTripDetails();
	}

	return 0;
}