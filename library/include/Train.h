//
// Created by Maciej on 23.12.2018.
//

#ifndef TICKETSTRAINSYSTEM_TRAIN_H
#define TICKETSTRAINSYSTEM_TRAIN_H

#include <string>
#include <sstream>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_io.hpp>

typedef boost::uuids::uuid uuid;


class Train {
private:
    int maxSpeed;
    uuid id;
    int numberOfSeats= 22000;
    int numberOfSeatsOccupated=0;
public:
    Train(int maxSpeed, int numberOfSeats, uuid id);
    Train(int maxSpeed, uuid id);
    virtual ~Train();
    virtual std::string displayTrainInfo();
    virtual double priceMultiplier() = 0;
    int getNumberOfSeats();
    int getNumberOfSeatsOccupated();
    void occupateSeat();
    int getMaxSpeed();
    uuid getID();

};


#endif //TICKETSTRAINSYSTEM_TRAIN_H
