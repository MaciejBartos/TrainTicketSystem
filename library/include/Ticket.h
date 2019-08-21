//
// Created by Maciej on 23.12.2018.
//

#ifndef TICKETSTRAINSYSTEM_TICKET_H
#define TICKETSTRAINSYSTEM_TICKET_H

#include <string>
#include <memory>
#include <boost/date_time/local_time/local_time.hpp>

#include "Train.h"

typedef std::shared_ptr<Train> train_ptr;

class Ticket {
private:
    int distance;
    boost::local_time::local_date_time buyTime;
    uuid id;
    double price;
    train_ptr train;
public:
    Ticket(int distance, boost::local_time::local_date_time buyTime, train_ptr train, double price, uuid id);
    ~Ticket();
    std::string tricketInfo();
    int getDistance();
    boost::local_time::local_date_time getBuyTime();
    uuid getID();
    double getPrice();


};


#endif //TICKETSTRAINSYSTEM_TICKET_H
