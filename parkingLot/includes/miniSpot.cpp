#include "parkingSpot.hpp"

class MiniSpot : public ParkingSpot {
public:
    MiniSpot() : ParkingSpot() {}
    double cost (){
        return 30.0;
    }
};