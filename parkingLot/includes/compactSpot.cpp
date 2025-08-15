#include "parkingSpot.hpp"

class CompactSpot : public ParkingSpot {
public:
    CompactSpot () : ParkingSpot() {}
    double cost (){
        return 40.0;
    }
};