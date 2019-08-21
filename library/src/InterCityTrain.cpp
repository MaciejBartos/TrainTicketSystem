#include "InterCityTrain.h"

InterCityTrain::InterCityTrain(int maxSpeed, char trainClass, int numberOfSeats, uuid id) : Train(maxSpeed, numberOfSeats, id) {
    this->trainClass = trainClass;
}

InterCityTrain::~InterCityTrain() {
}

std::string InterCityTrain::displayTrainInfo() {
    std::stringstream ss;
    ss << Train::displayTrainInfo() << " Ilosc miejsc: " << getNumberOfSeats() << " Ilosc miejsc zajetych: "
       << getNumberOfSeatsOccupated() << " Klasa pociagu: " << trainClass;
    return ss.str();
}

double InterCityTrain::trainClassMultiplier() {
    double multiplier = 0;
    switch(trainClass){
        case 'A':
            multiplier = 1.1;
            break;
        case 'B':
            multiplier = 1.2;
            break;
        case 'S':
            multiplier = 1.5;
            break;
        default:break;
    }
    return multiplier;
}

double InterCityTrain::priceMultiplier() {
    return trainClassMultiplier();
}

char InterCityTrain::getTrainClass() {
    return trainClass;
}
