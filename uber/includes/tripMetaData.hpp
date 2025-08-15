#pragma once
#include "rider.hpp"
#include "driver.hpp"

class TripMetaData {
	Location* srcLoc;
	Location* dstLoc;
	RATING riderRating;
	RATING driverRating;
public:
	TripMetaData(Location* pSrcLoc, Location* pDstLoc, RATING pRiderRating);
	RATING getRiderRating();
	RATING getDriverRating();
	void setDriverRating(RATING pDriverRating);
};
