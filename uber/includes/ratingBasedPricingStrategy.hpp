#pragma once

#include "pricingStrategy.hpp"

class RatingBasedPricingStrategy : public PricingStrategy {
public:
    double calculatePrice(TripMetaData* pTripMetaData) {
        double price = Util::isHighRating(pTripMetaData->getRiderRating()) ? 65.0 : 55.0;
        cout << "Based on " << Util::ratingToString(pTripMetaData->getRiderRating()) << 
			" rider rating, price of the trip is " << price << endl;
		return price;
    }
};