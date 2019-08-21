//
// Created by Maciej on 23.12.2018.
//

#ifndef TICKETSTRAINSYSTEM_REGIONALTRAIN_H
#define TICKETSTRAINSYSTEM_REGIONALTRAIN_H

#include "Train.h"

class RegionalTrain: public Train {
public:
    //dodac parametr typu UUID!!
    RegionalTrain(int maxSpeed, uuid id);
    ~RegionalTrain();
    std::string displayTrainInfo();
    double priceMultiplier();
};


#endif //TICKETSTRAINSYSTEM_REGIONALTRAIN_H
