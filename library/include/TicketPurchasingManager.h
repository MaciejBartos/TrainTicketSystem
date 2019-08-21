//
// Created by Maciej on 23.12.2018.
//

#ifndef TICKETSTRAINSYSTEM_TICKETPURCHASINGMANAGER_H
#define TICKETSTRAINSYSTEM_TICKETPURCHASINGMANAGER_H

#include <memory>
#include "TicketRepository.h"
#include "Client.h"
#include "TrainManager.h"

typedef std::shared_ptr<TicketRepository> ticketRepository_ptr;
typedef std::shared_ptr<TrainManager> trainManager_ptr;
typedef std::shared_ptr<Client> client_ptr;

class TicketPurchasingManager {
private:
    ticketRepository_ptr ticketRepository;
    trainManager_ptr trainManager;
public:
    TicketPurchasingManager(ticketRepository_ptr ticketRepository,
                            trainManager_ptr trainManager);

    ~TicketPurchasingManager();

    void buyTicket(client_ptr client, int distance, boost::local_time::local_date_time buyTime, train_ptr train,
                   double price, uuid id);
};


#endif //TICKETSTRAINSYSTEM_TICKETPURCHASINGMANAGER_H
