#include <iostream>


#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/date_time/local_time/local_time.hpp>
#include <InterCityTrain.h>
#include <RegionalTrain.h>
#include <TrainRepository.h>
#include <TrainManager.h>
#include <TicketRepository.h>
#include <TicketPurchasingManager.h>
#include <ClientRepository.h>
#include <ClientManager.h>
#include <Client.h>

using namespace std;


typedef shared_ptr<ClientManager> clientManager_ptr;
typedef shared_ptr<TicketPurchasingManager> ticketPurchasingManager_ptr;

int main() {
    boost::uuids::random_generator randomID;
    boost::local_time::time_zone_ptr zone(new boost::local_time::posix_time_zone("+2UTC-01,J301/03,J84/03"));
    boost::local_time::local_date_time ldt = boost::local_time::local_sec_clock::local_time(zone);

    train_ptr t1(new InterCityTrain(200,'S',333,randomID()));
    train_ptr t2(new InterCityTrain(210,'A',2,randomID()));
    train_ptr t3(new RegionalTrain(157,randomID()));
    train_ptr t4(new RegionalTrain(150,randomID()));
    trainRepository_ptr tr(new TrainRepository());
    trainManager_ptr tm(new TrainManager(tr));
    tm->addTrainToRepository(t1);
    tm->addTrainToRepository(t2);
    tm->addTrainToRepository(t3);
    ticketRepository_ptr br(new TicketRepository());
    ticketPurchasingManager_ptr bm(new TicketPurchasingManager(br,tm));
    clientRepository_ptr cr(new ClientRepository());
    clientManager_ptr cm(new ClientManager(cr));
    client_ptr c1(new Client(randomID(), "kasztanowa", "galkowek"));
    client_ptr c2(new Client(randomID(), "kasztanowa", "galkowek"));
    client_ptr c3(new Client(randomID(), "kasztanowa", "galkowek"));
    cm->addClientToRepository(c1);
    cm->addClientToRepository(c1);
    cm->addClientToRepository(c3);
    bm->buyTicket(c3,67,ldt,t3,23,randomID());
    bm->buyTicket(c1,67,ldt,t2,23,randomID());
    bm->buyTicket(c1,67,ldt,t2,23,randomID());
    return 0;
}