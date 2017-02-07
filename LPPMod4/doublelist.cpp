#include "doublelist.h"
#include <iostream>
#include <string>
using namespace std;


void createList(List &l){
    first(l) = NULL;
    last(l) = NULL;
}

address alokasi(infotype x){
    address p = new elmList;
    info(p).nopol = x.nopol;
    info(p).warna = x.warna;
    next(p) = NULL;
    prev(p) = NULL;

    return p;
}

void dealokasi(address &p){
    delete p;
}
void insertFirst(List &l , address p){
    if (first(l) == NULL) {
        first(l) = p;
        last(l) = p;
    } else {
        next(p) = first(l);
        first(l)->prev = p;
        first(l) = p;
    }
}
void insertLast(List &l , address p){
    if (first(l) == NULL) {
        first(l) = p;
        last(l) = p;
    } else {
        prev(p) = last(l);
        last(l)->next = p;
        last(l) = p ;
    }
}
address findElm(List l , infotype x){
    if (first(l) == NULL) {
        return NULL;
    }
    else {
        address p = first(l);
        while ( p != NULL && info(p).nopol != x.nopol) {
            p = next(p);
        }
        if (p == NULL) {
            return NULL;
        } else {
            return p;
        }
    }
}

void deleteFirst(List &l , address &p){
    if (first(l) != NULL) {
        if (first(l) == last(l)) {
            first(l) = NULL;
            last(l) = NULL;
        } else {
            first(l) = next(p);
            first(l)->prev = NULL;
            next(p) = NULL;
            prev(p) = NULL;
        }
    } else {
        cout << "List sudah kosong " << endl;
    }
}

void deleteLast(List &l , address &p){
    if (first(l) != NULL) {
         if (first(l) == last(l)) {
            first(l) == NULL;
            last(l) == NULL;
         } else {
            p = last(l);
            last(l) = last(l)->prev;
            prev(p) = NULL;
            last(l)->next = NULL;
         }
    } else {
        cout << "List sudah kosong" << endl;
    }
}

void printInfo(List &l){
    address p = first(l);
    if (first(l) != NULL){
        while (p != NULL) {
            cout << "No Polisi \t : " << info(p).nopol << endl;
            cout << "Warna \t\t : " << info(p).warna << endl;
            p = next(p);
        }
    } else {
        cout << "list kosong" << endl;
    }
}
