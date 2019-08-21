#include <boost/test/unit_test.hpp>
#include "TicketPurchasingManager.h"
#include "Address.h"
#include "TrainManager.h"
#include "InterCityTrain.h"
#include "RegionalTrain.h"
#include "Ticket.h"
#include "ClientRepository.h"
#include "ClientManager.h"
#include "TicketRepository.h"
#include "Exception.h"
#include <iostream>

using namespace std;

typedef shared_ptr<ClientManager> clientManager_ptr;
typedef shared_ptr<TicketPurchasingManager> ticketPurchasingManager_ptr;

BOOST_AUTO_TEST_SUITE(TestSuiteCorrect)

    BOOST_AUTO_TEST_CASE(ClientCase) {
        boost::uuids::random_generator randomID;
        uuid id = randomID();
        Client client(id, "kasztanowa", "galkowek");
        BOOST_REQUIRE_EQUAL(client.getID(), id);
        BOOST_REQUIRE_EQUAL(client.getAddress(), "galkowek kasztanowa");
        client.changeAddress("gala","metropolia");
        BOOST_REQUIRE_EQUAL(client.getAddress(), "metropolia gala");
    }
    BOOST_AUTO_TEST_CASE(AddresCase){
        Address a("lodzka","warszawa");
        BOOST_REQUIRE_EQUAL(a.getStreet(),"lodzka");
        BOOST_REQUIRE_EQUAL(a.getCity(),"warszawa");
        a.setCity("lodz");
        a.setStreet("kasztanowa");
        BOOST_REQUIRE_EQUAL(a.getStreet(),"kasztanowa");
        BOOST_REQUIRE_EQUAL(a.getCity(),"lodz");
        //BOOST_REQUIRE_EQUAL(client.address->getNumber(),clinnt2.address->getNumber());
    }
    BOOST_AUTO_TEST_CASE(TrainCase){
        boost::uuids::random_generator randomID;
        uuid id = randomID();
        RegionalTrain r1(150,id);
        BOOST_REQUIRE_EQUAL(r1.getID(), id);
        BOOST_REQUIRE_EQUAL(r1.getMaxSpeed(), 150);
        BOOST_REQUIRE_EQUAL(r1.getNumberOfSeats(), 22000);
        BOOST_REQUIRE_EQUAL(r1.getNumberOfSeatsOccupated(), 0);
        r1.occupateSeat();
        r1.occupateSeat();
        BOOST_REQUIRE_EQUAL(r1.getNumberOfSeatsOccupated(), 2);
        BOOST_REQUIRE_CLOSE(r1.priceMultiplier(),1.0,0.00001);
        id = randomID();
        InterCityTrain i1(200,'S',333,id);
        BOOST_REQUIRE_EQUAL(i1.getID(), id);
        BOOST_REQUIRE_EQUAL(i1.getMaxSpeed(), 200);
        BOOST_REQUIRE_EQUAL(i1.getNumberOfSeats(), 333);
        BOOST_REQUIRE_EQUAL(i1.getNumberOfSeatsOccupated(), 0);
        i1.occupateSeat();
        BOOST_REQUIRE_EQUAL(i1.getNumberOfSeatsOccupated(), 1);
        BOOST_REQUIRE_CLOSE(i1.priceMultiplier(),1.5,0.00001);
        BOOST_REQUIRE_EQUAL(i1.getTrainClass(),'S');


}
    BOOST_AUTO_TEST_CASE(TicketCase){
        boost::uuids::random_generator randomID;
        uuid id1 = randomID();
        uuid id2 = randomID();
        boost::local_time::time_zone_ptr zone(new boost::local_time::posix_time_zone("+2UTC-01,J301/03,J84/03"));
        boost::local_time::local_date_time ldt = boost::local_time::local_sec_clock::local_time(zone);

        train_ptr t1(new InterCityTrain(200,'S',333,id1));
        Ticket b(45,ldt,t1,12,id2);
        BOOST_REQUIRE_EQUAL(b.getID(),id2);
        BOOST_REQUIRE_EQUAL(b.getBuyTime(),ldt);
        BOOST_REQUIRE_EQUAL(b.getDistance(),45);
        BOOST_REQUIRE_CLOSE(b.getPrice(),12*t1->priceMultiplier(),0.00001);

}

    BOOST_AUTO_TEST_CASE(ClientRepo){
        boost::uuids::random_generator randomID;
        clientRepository_ptr clientRepository(new ClientRepository());
        clientManager_ptr clientManager(new ClientManager(clientRepository));
        client_ptr c1(new Client(randomID(), "kasztanowa", "galkowek"));
        client_ptr c2(new Client(randomID(), "kasztanowa", "galkowek"));
        client_ptr c3(new Client(randomID(), "kasztanowa", "galkowek"));
        BOOST_REQUIRE_EQUAL(clientRepository->getClients().size(),0);
        clientManager->addClientToRepository(c1);
        clientManager->addClientToRepository(c1);
        clientManager->addClientToRepository(c2);
        BOOST_REQUIRE_EQUAL(clientRepository->getClients().size(),2);
        clientManager->addClientToRepository(c3);
        BOOST_REQUIRE_EQUAL(clientRepository->getClients().size(),3);
        clientManager->deleteClientFromRepository(c1);
        BOOST_REQUIRE_EQUAL(clientRepository->getClients().size(),2);
}

    BOOST_AUTO_TEST_CASE(TrainRepo){
        boost::uuids::random_generator randomID;
        train_ptr t1(new InterCityTrain(200,'S',333,randomID()));
        train_ptr t2(new InterCityTrain(200,'S',333,randomID()));
        train_ptr t3(new RegionalTrain(150,randomID()));
        train_ptr t4(new RegionalTrain(150,randomID()));
        trainRepository_ptr tr(new TrainRepository());
        trainManager_ptr tm(new TrainManager(tr));
        BOOST_REQUIRE_EQUAL(tr->getTrains().size(),0);
        BOOST_REQUIRE_EQUAL(tm->isTrainInRepository(t4),false);
        tm->addTrainToRepository(t1);
        tm->addTrainToRepository(t2);
        tm->addTrainToRepository(t2);
        tm->addTrainToRepository(t3);
        tm->addTrainToRepository(t4);
        BOOST_REQUIRE_EQUAL(tr->getTrains().size(),4);
        BOOST_REQUIRE_EQUAL(tm->isTrainInRepository(t2),true);
        tm->deleteTrainFromRepository(t3);
        tm->deleteTrainFromRepository(t2);
        BOOST_REQUIRE_EQUAL(tr->getTrains().size(),2);
        BOOST_REQUIRE_EQUAL(tm->isTrainInRepository(t2),false);


}

    BOOST_AUTO_TEST_CASE(General){
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
        BOOST_REQUIRE_EQUAL(br->getSize(),1);
        BOOST_REQUIRE_EQUAL(t3->getNumberOfSeatsOccupated(),1);
        bm->buyTicket(c1,67,ldt,t2,23,randomID());
        bm->buyTicket(c1,67,ldt,t2,23,randomID());
        BOOST_CHECK_THROW(bm->buyTicket(c1,67,ldt,t2,23,randomID()),Exception);
        BOOST_CHECK_THROW(bm->buyTicket(c1,67,ldt,t4,23,randomID()),Exception);
        BOOST_REQUIRE_EQUAL(t4->getNumberOfSeatsOccupated(),0);
        BOOST_REQUIRE_EQUAL(t2->getNumberOfSeatsOccupated(),2);
        BOOST_REQUIRE_EQUAL(br->getSize(),3);
}

BOOST_AUTO_TEST_SUITE_END()