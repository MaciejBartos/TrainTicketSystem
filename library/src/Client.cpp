#include "Client.h"

Client::Client(uuid id, std::string street, std::string city){
    this->id = id;
    this->address = std::make_shared<Address>(street, city);
}

Client::~Client() {
}

void Client::changeAddress(std::string street, std::string city) {
    address->setStreet(street);
    address->setCity(city);

}

std::string Client::displayAllTickets() {
    std::stringstream ss;
    for (auto &ticket: tickets){
        ss << ticket->tricketInfo() << std::endl;
    }
    return ss.str();
}

void Client::addTicket(ticket_ptr ticket) {
    tickets.push_back(ticket);
}

uuid Client::getID() {
    return id;
}

std::string Client::getAddress() {
    std::ostringstream s;
    s << address->getCity()<< " " << address->getStreet();
    return s.str();
}
