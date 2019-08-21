#include "Train.h"

Train::Train(int maxSpeed, int numberOfSeats, uuid id) {
    this->maxSpeed = maxSpeed;
    this->numberOfSeats = numberOfSeats;
    this->id = id;

}

Train::Train(int maxSpeed, uuid id) {
    this->maxSpeed = maxSpeed;
    this->id = id;
}

Train::~Train() {
}

std::string Train::displayTrainInfo() {
    std::stringstream ss;
    ss << "Predkosc maksymalna: " << maxSpeed << " id: " << id;
    return ss.str();
}



int Train::getNumberOfSeats() {
    return numberOfSeats;
}

int Train::getNumberOfSeatsOccupated() {
    return numberOfSeatsOccupated;
}

void Train::occupateSeat() {
    numberOfSeatsOccupated++;
}

int Train::getMaxSpeed() {
    return maxSpeed;
}

uuid Train::getID() {
    return id;
}
