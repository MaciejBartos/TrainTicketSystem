#include "TicketPurchasingManager.h"
#include "Exception.h"

TicketPurchasingManager::TicketPurchasingManager(ticketRepository_ptr ticketRepository,
                                                 trainManager_ptr trainManager) {
    this->ticketRepository = ticketRepository;
    this->trainManager = trainManager;
}

TicketPurchasingManager::~TicketPurchasingManager() {
}

void TicketPurchasingManager::buyTicket(client_ptr client, int distance, boost::local_time::local_date_time buyTime,
                                        train_ptr train, double price, uuid id) {
    if (trainManager->isTrainInRepository(train)) {
        if (train->getNumberOfSeatsOccupated() < train->getNumberOfSeats()){
            ticket_ptr ticket(new Ticket(distance, buyTime, train, price,id));

            ticketRepository->addTicket(ticket);
            client->addTicket(ticket);
            train->occupateSeat();

        }
        else{
            throw Exception("Nie udalo sie kupic biletu! Brak miejsc.");
        }
    }
    else{
        throw  Exception("Brak pociagu w repozytorium!");
    }
}
