#include "tripMetaData.hpp"


TripMetaData::TripMetaData(Location* pSrcLoc, Location* pDstLoc, RATING pRiderRating) :
    srcLoc(pSrcLoc), dstLoc(pDstLoc), riderRating(pRiderRating) {
    driverRating = RATING::UNASSIGNED;
}

RATING TripMetaData::getRiderRating() {
    return riderRating;
}
RATING TripMetaData::getDriverRating() {
    return driverRating;
}
void TripMetaData::setDriverRating(RATING pDriverRating) {
    driverRating = pDriverRating;
}