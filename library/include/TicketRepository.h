//
// Created by Maciej on 23.12.2018.
//

#ifndef TICKETSTRAINSYSTEM_TICKETREPOSITORY_H
#define TICKETSTRAINSYSTEM_TICKETREPOSITORY_H

#include <vector>
#include <memory>
#include "Ticket.h"

class TicketRepository {
private:
    std::vector<std::shared_ptr<Ticket>> tickets;
public:
    TicketRepository();
    ~TicketRepository();
    std::string allTicketsInfo();
    void addTicket(std::shared_ptr<Ticket> ticket);
    int getSize();
};


#endif //TICKETSTRAINSYSTEM_TICKETREPOSITORY_H
