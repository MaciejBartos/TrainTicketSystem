#include "Ticket.h"

Ticket::Ticket(int distance, boost::local_time::local_date_time buyTime, train_ptr train,
               double price, uuid id): buyTime(buyTime) {
    this->price=price*train->priceMultiplier();
    this->distance = distance;
    this->id=id;
    this->train = train;

}

Ticket::~Ticket() {
}

std::string Ticket::tricketInfo() {
    std::stringstream ss;
    ss << "id: " << id << " Data kupna: " << buyTime << " Dlugosc trasy: " << distance << " Cena: " << price;
    return ss.str();
}

int Ticket::getDistance() {
    return distance;
}

boost::local_time::local_date_time Ticket::getBuyTime() {
    return buyTime;
}

uuid Ticket::getID() {
    return id;
}

double Ticket::getPrice() {
    return price;
}
