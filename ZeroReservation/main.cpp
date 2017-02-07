#include <iostream>
#include "zeroReservation.h"

#include <conio.h>

using namespace std;

int main()
{
    schedules schList;
    plane planeList;
    passenger passengerList;

    dataSchedules x;
    dataPlane y;
    dataPassenger z;

    createListSchedules(schList);
    addressSchedules sch;

   // createListPassenger(passengerList);
    //createListPlane(planeList);

    /*----------  Dummies  ----------*/

    x.date = "11/25/2016";
    x.schID = "ZR-01";
    sch = alokasiSch(x);
    insertFirstSch(schList , sch);

    x.date = "12/25/2016";
    x.schID = "ZR-02";
    sch = alokasiSch(x);
    insertLastSch(schList , sch);

    x.date = "13/25/2016";
    x.schID = "ZR-03";
    sch = alokasiSch(x);
    insertLastSch(schList, sch);

    x.date = "14/25/2016";
    x.schID = "ZR-04";
    sch = alokasiSch(x);
    insertFirstSch(schList , sch);

    createListPlane(planeList);
    addressPlane  pln;
    y.planeID = "GA-01";
    y.type = "A-737";
    y.route = "KNO - BDO";
    y.price = 100000;
    y.capacity = 480;
    pln = alokasiPlane(y);
    insertFirstPlane(planeList , pln);

    y.planeID = "GA-02";
    y.type = "A-737";
    y.route = "KNO - BDO";
    y.price = 123456;
    y.capacity = 150;
    pln = alokasiPlane(y);
    insertFirstPlane(planeList , pln);

    y.planeID = "GA-03";
    y.type = "A-737";
    y.route = "KNO - BDO";
    y.price = 123456;
    y.capacity = 200;
    pln = alokasiPlane(y);
    insertFirstPlane(planeList , pln);


    createListPassenger(passengerList);
    addressPassenger psgr;
    z.passengerID = "MR-01";
    z.age = 21;
    z.gender = "Male";
    z.name = "Satrya";
    z.password = "1";
    z.username = "user1";
    z.address = "Bandung";
    psgr = alokasiPassenger(z);
    insertFirstPas(passengerList , psgr);

    z.passengerID = "MR-02";
    z.age = 25;
    z.gender = "Male";
    z.name = "Alfian";
    z.password = "2";
    z.username = "user2";
    z.address = "Bandung";
    psgr = alokasiPassenger(z);
    insertLastPas(passengerList , psgr);

    z.passengerID = "MR-03";
    z.age = 22;
    z.gender = "Male";
    z.name = "Boy";
    z.username = "user3";
    z.password = "3";
    z.address = "Bandung";
    psgr = alokasiPassenger(z);
    insertFirstPas(passengerList , psgr);

        z.passengerID = "a";
    z.age = 22;
    z.gender = "Male";
    z.name = "Boy";
    z.username = "a";
    z.password = "a";
    z.address = "Bandung";
    psgr = alokasiPassenger(z);
    insertFirstPas(passengerList , psgr);




    mainMenu(schList , planeList , passengerList);

    return 0;
}
