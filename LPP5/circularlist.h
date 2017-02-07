#ifndef CIRCULARLIST_H_INCLUDED
#define CIRCULARLIST_H_INCLUDED
#include <iostream>
using namespace std;
#define nil NULL
#define first(l) l.first
#define next(p) p->next
#define info(p) p->info

typedef int infotype;

typedef struct elmList *address;

struct elmList{
    infotype info;
    address next;
};

struct List {
    address first;
};

void createList(List &l);
address alokasi(infotype x);
void dealokasi(address &p);
void insertFirst(List &l , address p);
void insertAfter(List &l , address prec , address p);
void insertLast(List &l , address p);
void deleteFirst(List &l , address &p);
void deleteAfter(List &l , address prec , address &p);
void deleteLast(List &l , address &p);
address findElm(List l , infotype x);
void printInfo(List l);

void clone(List l , List &m , List &n);

elmList salin(elmList List);

#endif // CIRCULARLIST_H_INCLUDED
