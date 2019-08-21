#include "TicketRepository.h"

TicketRepository::TicketRepository() {

}

TicketRepository::~TicketRepository() {
}

std::string TicketRepository::allTicketsInfo() {
    std::stringstream ss;
    for (auto &ticket : tickets) {
        ss << ticket->tricketInfo() << std::endl;
    }
    return ss.str();
}

void TicketRepository::addTicket(std::shared_ptr<Ticket> ticket) {
    tickets.push_back(ticket);
}

int TicketRepository::getSize() {
    return tickets.size();
}
