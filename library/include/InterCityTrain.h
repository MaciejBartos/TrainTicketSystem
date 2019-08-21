//
// Created by Maciej on 23.12.2018.
//

#ifndef TICKETSTRAINSYSTEM_INTERCITYTRAIN_H
#define TICKETSTRAINSYSTEM_INTERCITYTRAIN_H

#include <string>
#include "Train.h"

class InterCityTrain: public Train {
private:
    char trainClass;
public:
    //dodac parametr typu UUID!
    InterCityTrain(int maxSpeed, char trainClass, int numberOfSeats, uuid id);
    ~InterCityTrain();
    std::string displayTrainInfo();
    double trainClassMultiplier();
    double priceMultiplier();
    char getTrainClass();
};


#endif //TICKETSTRAINSYSTEM_INTERCITYTRAIN_H
