#include "Address.h"

Address::Address(std::string street, std::string city) {
    this->street=street;
    this->city=city;
}

Address::~Address() {
}

void Address::setStreet(std::string street) {
    this->street=street;
}

void Address::setCity(std::string city) {
    this->city=city;

}

std::string Address::getStreet() {
    return street;
}

std::string Address::getCity() {
    return city;
}
