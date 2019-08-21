//
// Created by Maciej on 23.12.2018.
//

#ifndef TICKETSTRAINSYSTEM_ADDRESS_H
#define TICKETSTRAINSYSTEM_ADDRESS_H


#include <string>

class Address {
private:
    std::string street;
    std::string city;
public:
    Address(std::string street, std::string city);
    ~Address();
    void setStreet(std::string street);
    void setCity(std::string city);
    std::string getStreet();
    std::string getCity();
};


#endif //TICKETSTRAINSYSTEM_ADDRESS_H
