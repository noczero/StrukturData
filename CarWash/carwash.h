#ifndef CARWASH_H_INCLUDED
#define CARWASH_H_INCLUDED

#include <iostream>
using namespace std;

//#define nil NULL
//#define info(p) (p)->info
//#define next(p) (p)->next
//#define first(l) (l).first

#define nil NULL
#define next(p) p->next
#define first(l) l.first
#define info(p) p->info

struct infoType {
	char noPol[30];
	char merkMobil[30];
};

typedef struct elmList *address;

struct elmList {
	infoType info;
	address next;
};

struct list {
	address first;
};

void createList(list &l);
void dealokasi(address p);
address alokasi(infoType x);

void insertFirst(list &l , address p);
void insertLast(list &l , address p);
void insertAfter(address q , address p);

void deleteFirst(list &l , address p);
void deleteLast(list &l , address p);
void deleteAfter(address q , address &p);

address searchData(list l , infoType x);
address searchDataBefore(list l , infoType x);
void updateData(address p , infoType y);
void printInfo(list l);

#endif
