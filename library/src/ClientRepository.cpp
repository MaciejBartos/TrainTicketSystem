#include "ClientRepository.h"

ClientRepository::ClientRepository() {
}

ClientRepository::~ClientRepository() {
}

void ClientRepository::addClient(client_ptr client) {
    clients.push_back(client);
}

void ClientRepository::deleteClient(int position) {
    clients.erase(clients.begin()+position);
}

std::vector<client_ptr> ClientRepository::getClients() {
    return clients;
}
