//
// Created by Maciej on 23.12.2018.
//

#ifndef TICKETSTRAINSYSTEM_TRAINREPOSITORY_H
#define TICKETSTRAINSYSTEM_TRAINREPOSITORY_H

#include <vector>
#include <memory>
#include "Train.h"

typedef std::shared_ptr<Train> train_ptr;

class TrainRepository {
private:
    std::vector<train_ptr> trains;
public:
    TrainRepository();
    ~TrainRepository();
    void addTrain(train_ptr train);
    void deleteTrain(int position);
    std::vector<train_ptr> getTrains();
};


#endif //TICKETSTRAINSYSTEM_TRAINREPOSITORY_H
