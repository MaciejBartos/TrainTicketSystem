#include "ClientManager.h"

ClientManager::ClientManager(clientRepository_ptr clientRepository) {
    this->clientRepository = clientRepository;
}

ClientManager::~ClientManager() {
}

void ClientManager::addClientToRepository(client_ptr client) {
    bool alreadyInRepository = false;
    for (const auto &i : clientRepository->getClients()) {
        if(i == client){
            alreadyInRepository = true;
        }
    }
    if (!alreadyInRepository){
        clientRepository->addClient(client);
    }
}

void ClientManager::deleteClientFromRepository(client_ptr client) {
    for (int position = 0; position < clientRepository->getClients().size(); position++) {
        if (clientRepository->getClients()[position] == client){
            clientRepository->deleteClient(position);
        }
    }
}
