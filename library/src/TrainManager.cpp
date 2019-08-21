#include "TrainManager.h"

TrainManager::TrainManager(trainRepository_ptr trainRepository) {
    this->trainRepository = trainRepository;
}


TrainManager::~TrainManager() {
}

void TrainManager::addTrainToRepository(train_ptr train) {
    bool trainAlreadyInRepository = false;
    for (int i = 0; i < trainRepository->getTrains().size(); ++i) {
        if (trainRepository->getTrains()[i] == train){
            trainAlreadyInRepository = true;
        }
    }
    if (!trainAlreadyInRepository){
        trainRepository->addTrain(train);
    }
}

void TrainManager::deleteTrainFromRepository(train_ptr train) {
    for (int i = 0; i < trainRepository->getTrains().size(); ++i) {
        if (trainRepository->getTrains()[i] == train){
            trainRepository->deleteTrain(i);
        }
    }
}

bool TrainManager::isTrainInRepository(train_ptr train) {
    bool trainIsInRepository = false;
    for (int i = 0; i < trainRepository->getTrains().size(); ++i) {
        if (train == trainRepository->getTrains()[i]){
            trainIsInRepository = true;
        }
    }
    return trainIsInRepository;
}
