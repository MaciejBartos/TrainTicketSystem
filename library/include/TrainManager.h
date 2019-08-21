//
// Created by Maciej on 23.12.2018.
//

#ifndef TICKETSTRAINSYSTEM_TRAINMANAGER_H
#define TICKETSTRAINSYSTEM_TRAINMANAGER_H

#include <memory>
#include "TrainRepository.h"

typedef std::shared_ptr<TrainRepository> trainRepository_ptr;

class TrainManager {
private:
    trainRepository_ptr trainRepository;
public:
    TrainManager(trainRepository_ptr trainRepository);
    ~TrainManager();
    void addTrainToRepository(train_ptr train);
    void deleteTrainFromRepository(train_ptr train);
    bool isTrainInRepository(train_ptr train);
};


#endif //TICKETSTRAINSYSTEM_TRAINMANAGER_H
