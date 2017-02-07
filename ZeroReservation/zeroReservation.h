#ifndef ZERORESERVATION_H_INCLUDED
#define ZERORESERVATION_H_INCLUDED
/*=======================================
=            ZeroReservation            =
=======================================*/
/**

	TODO:
	- import library
	- Procedure & Function
	- MultiLinked List

 */

/**
 *
 * library
 *
 */
 #include <iostream>
 #include <string.h>
 #include <windows.h>
 #include <conio.h>
 #include <ctime>

#define next(p) p->next
#define prev(p) p->prev
#define info(p) p->info
#define last(l) l.last
#define first(l) l.first
 using namespace std;

 /*----------  Pointer Declaration  ----------*/
 typedef struct elmPlane *addressPlane;
 typedef struct elmSchedules *addressSchedules;
 typedef struct elmPassenger *addressPassenger;
 typedef struct elmListRelasi *addressRelasi;
 typedef struct elmListRelasi2 *addressRelasi2;

/*----------  Data Type Declaration  ----------*/
 struct dataPlane {
 	string planeID;
 	string type;
 	string route;
 	long int price;
 	int capacity;
 };

 struct dataSchedules
 {
 	string schID;
 	string date;
 };

 struct dataPassenger{
 	string passengerID;
 	string name;
 	string username;
 	string password;
 	int age;
 	string gender;
 	string address;
 };


/*----------  Double Linked List Declaration ----------*/
struct schedules
{
	addressSchedules first;
	addressSchedules last;
};

struct plane
{
	addressPlane first;
	addressPlane last;
};

struct listRelasi{
    addressRelasi first;
    addressRelasi last;
};

/*----------  Single Linked List Declaration  ----------*/
struct passenger
{
	addressPassenger first;
};

struct listRelasi2{
	addressRelasi2 first;
};

/*----------  Element of Multi Linked List  ----------*/

struct elmSchedules
{
	dataSchedules info;
	addressSchedules next;
	addressSchedules prev;
	listRelasi child;
};

struct elmPlane
{
	dataPlane info;
	addressPlane next;
	addressPlane prev;
	listRelasi2 child;
};

struct elmPassenger
{
	dataPassenger info;
	addressPassenger next;
};

struct elmListRelasi {
    addressRelasi next;
    addressRelasi prev;
    addressPlane info ;
};

struct elmListRelasi2 {
	addressRelasi2 next;
	addressPassenger info;
};




/*----------  Function & Procedure  ----------*/

/*===================================
=            Create List            =
===================================*/
void createListPlane(plane &l);
void createListSchedules(schedules &l);
void createListPassenger(passenger &l);
void createListRelasi(listRelasi &l);
void createListRelasi2(listRelasi2 &l);
/*=====  End of Create List  ======*/

/*==================================
=            Alocattion            =
==================================*/
addressSchedules alokasiSch(dataSchedules x);
addressPlane alokasiPlane(dataPlane x);
addressPassenger alokasiPassenger(dataPassenger x);
addressRelasi alokasiRelasi(addressPlane c);
addressRelasi2 alokasiRelasi2(addressPassenger c);
/*=====  End of Alocattion  ======*/


/*==============================
=            Insert            =
==============================*/
/*----------  Option Insert  ----------*/
void insertOption(char &pilih);
/*----------  Schedules  ----------*/
void insertSchedulesMain(schedules &l);
void insertFirstSch(schedules &l , addressSchedules p);
void insertLastSch(schedules &l , addressSchedules p);

/*----------  Plane  ----------*/
void insertPlaneMain(plane &l);
void insertFirstPlane(plane &l , addressPlane p);
void insertLastPlane(plane &l , addressPlane p);

/*----------  Passenger  ----------*/
void insertPassengerMain(passenger &l);
void insertFirstPas(passenger &l, addressPassenger p);
void insertLastPas(passenger &l , addressPassenger p);
/*----------  Relasi  ----------*/
void insertFirst(listRelasi &l, addressRelasi p);
void insertLast(listRelasi &l, addressRelasi p);
void insertFirstR2(listRelasi2 &l, addressRelasi2 p);
void insertLastR2(listRelasi2 &l, addressRelasi2 p);
/*=====  End of Insert  ======*/
/*----------  add  ----------*/
void addJadwaltoPlane(schedules &sch , plane &pln);
void addDataPassenger(passenger l , dataPassenger &x);
void addDataPlane(plane l , dataPlane &x);
void addDataSchedules(schedules l , dataSchedules &x);
void addPassengertoPlane(plane &pln , addressPassenger &pas);
/*=====  End of add  ======*/



/*==============================
=            Delete            =
==============================*/
/*----------  schedules  ----------*/
void deleteFirstSch(schedules &l);
void deleteLastSch(schedules &l);
void deleteSchbyID(schedules &l);
/*----------  plane  ----------*/
void deleteFirstPlane(plane &l);
void deleteLastPlane(plane &l);
void deletePlanebyID(plane &l);
/*----------  passenger  ----------*/
void deleteFirstPas(passenger &l);
void deleteLastPas(passenger &l);
void deletePasbyID(passenger &l);
/*----------  relasi  ----------*/
void deleteFirstRelasi(listRelasi &l);
void deleteLastRelasi(listRelasi &l);
void deleteRelasibyID(schedules &l);
void deleteFirstR2(listRelasi2 &l);
void deleteLastR2(listRelasi2 &l);
void deleteRelasi2byID(plane &l);

void pembatalan(plane &l , addressPassenger q);
/*=====  End of Delete  ======*/


/*============================
=            Edit            =
============================*/
void editSchedules(schedules &l);
void editPlane(plane &l);
void editPassenger(passenger &l);
void editProfile(passenger &l , addressPassenger p);
/*=====  End of Edit  ======*/


/*========================================
=            Find & Searching            =
========================================*/
addressPlane findElmPlane(plane l , string planeID);
addressSchedules findElmSchedules(schedules l, string schID);
addressPassenger findElmPassenger(passenger l , string passengerID);
addressRelasi findElmRelasi(listRelasi l , string planeID);
addressRelasi2 findElmRelasi2(listRelasi2 l , string passID);
addressPlane findTypePlane(plane l , dataPlane x);
/*=====  End of Find & Searching  ======*/

/*=============================
=            Print            =
=============================*/

void printInfoSchedules(schedules l);
void printInfoPlane(plane l);
void printInfoPassenger(passenger l);
void printAll(schedules l);
void printSemua(schedules l);
void printSch_Pln(schedules l);
void printPesanan(plane l , addressPassenger p);
void printInfoRelasi(listRelasi l);
void printplane_passenger(plane l);
void printInfoRelasi2(listRelasi2 l);


/*=====  End of Print  ======*/


/*----------  menu  ----------*/
void menuPassanger(schedules &sch , plane &pln , passenger &pas);
void menuAdmin(schedules &sch , plane &pln , passenger &pas);
void mainMenu(schedules &sch, plane &pln , passenger &pas);
void menuTambah(schedules &sch, plane &pln , passenger &pas);
void menuHapus(schedules &sch , plane &pln , passenger &pas);
void menuEdit(schedules &sch , plane &pln , passenger &pas);
void pesanPenerbangan(schedules &sch , plane &pln , passenger &pas);

/*----------  check no element  ----------*/
bool checkPlaneID(plane l , string ID);
bool checkSchedulesID(schedules l , string ID);
bool checkPassengerID(passenger l , string ID);
bool checkRelasi2(listRelasi2 l , string ID);
bool checkRelasi(listRelasi l , string ID);
/*================================
=            #addpass            =
================================*/

void pesanPenerbangan(plane &l , addressPassenger psgr);
const string currentDateTime();
/*=====  End of #addpass  ======*/

/*==============================
=            #COunt            =
==============================*/
int countSchedules(schedules l);
int countPlane(plane l);
int countPassenger(passenger l);

/*=====  End of #COunt  ======*/


#endif // ZERORESERVATION_H_INCLUDED
