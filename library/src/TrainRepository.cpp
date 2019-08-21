#include "TrainRepository.h"

TrainRepository::TrainRepository() {

}

TrainRepository::~TrainRepository() {
}

void TrainRepository::addTrain(train_ptr train) {
    trains.push_back(train);
}

void TrainRepository::deleteTrain(int position) {
    trains.erase(trains.begin() + position);
}

std::vector<train_ptr> TrainRepository::getTrains() {
    return trains;
}

