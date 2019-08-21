#include "RegionalTrain.h"

RegionalTrain::RegionalTrain(int maxSpeed, uuid id) : Train(maxSpeed, id) {

}

RegionalTrain::~RegionalTrain() {
}

std::string RegionalTrain::displayTrainInfo() {
    return Train::displayTrainInfo();
}

double RegionalTrain::priceMultiplier() {
    return 1.0;
}
