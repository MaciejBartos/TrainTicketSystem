//
// Created by Maciej on 23.12.2018.
//

#ifndef TICKETSTRAINSYSTEM_CLIENTREPOSITORY_H
#define TICKETSTRAINSYSTEM_CLIENTREPOSITORY_H

#include <vector>
#include <memory>

#include "Client.h"

typedef std::shared_ptr<Client> client_ptr;

class ClientRepository {
private:
    std::vector<client_ptr> clients;
public:
    ClientRepository();
    ~ClientRepository();
    void addClient(client_ptr client);
    void deleteClient(int position);
    std::vector<client_ptr> getClients();
};


#endif //TICKETSTRAINSYSTEM_CLIENTREPOSITORY_H
