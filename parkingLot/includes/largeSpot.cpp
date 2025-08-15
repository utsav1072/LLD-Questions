#include "parkingSpot.hpp"

class LargeSpot : public ParkingSpot {
public:
    LargeSpot () : ParkingSpot() {}
    double cost (){
        return 50.0;
    }
};