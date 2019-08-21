//
// Created by Maciej on 23.12.2018.
//

#ifndef TICKETSTRAINSYSTEM_CLIENTMANAGER_H
#define TICKETSTRAINSYSTEM_CLIENTMANAGER_H

#include <memory>

#include "ClientRepository.h"

typedef std::shared_ptr<ClientRepository> clientRepository_ptr;
class ClientManager {
private:
    clientRepository_ptr clientRepository;
public:
    ClientManager(clientRepository_ptr clientRepository);
    ~ClientManager();
    void addClientToRepository(client_ptr client);
    void deleteClientFromRepository(client_ptr client);
};


#endif //TICKETSTRAINSYSTEM_CLIENTMANAGER_H
