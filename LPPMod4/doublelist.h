#ifndef DOUBLELIST_H_INCLUDED
#define DOUBLELIST_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

//#define nil NULL;
#define next(p) p->next
#define prev(p) p->prev
#define info(p) p->info
#define last(l) l.last
#define first(l) l.first

struct kendaraan {
    string nopol;
    string warna;
};

typedef kendaraan infotype;

typedef struct elmList *address;

struct elmList{
    infotype info;
    address next;
    address prev;
};

struct List{
    address first;
    address last;
};

void createList(List &l);
address alokasi(infotype x);
void dealokasi(address &p);
void insertFirst(List &l , address p);
void insertLast(List &l , address p);
address findElm(List l , infotype x);
void deleteFirst(List &l , address &p);
void deleteLast(List &l , address &p);
void printInfo(List &l);



#endif // DOUBLELIST_H_INCLUDED
