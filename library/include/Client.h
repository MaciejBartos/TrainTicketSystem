//
// Created by Maciej on 23.12.2018.
//

#ifndef TICKETSTRAINSYSTEM_CLIENT_H
#define TICKETSTRAINSYSTEM_CLIENT_H

#include <memory>
#include <vector>
#include <sstream>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>

#include "Address.h"
#include "Ticket.h"

typedef boost::uuids::uuid uuid;
typedef std::shared_ptr<Address> address_ptr;
typedef std::shared_ptr<Ticket> ticket_ptr;

class Client {
private:
    address_ptr address;
    std::vector<ticket_ptr> tickets;
    uuid id;
public:
    Client(uuid id, std::string street, std::string city);
    ~Client();
    void changeAddress(std::string street, std::string city);
    std::string displayAllTickets();
    void addTicket(ticket_ptr ticket);
    uuid getID();
    std::string getAddress();
};


#endif //TICKETSTRAINSYSTEM_CLIENT_H
