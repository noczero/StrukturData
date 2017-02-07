#include "circularlist.h"

void createList(List &l){
    first(l) = nil;
}

address alokasi(infotype x){
    address p = new elmList;
    info(p) = x;
    next(p) = nil;

    return p;
}

void dealokasi(address &p) {
    delete p;
}
void insertFirst(List &l , address p){
    if (first(l) == nil) {
        first(l) = p;
        next(p) = first(l);
    } else {
        address q = first(l);
        while (next(q) != first(l)) {
            q = next(q);
        }
        next(p) = first(l);
        next(q) = p;
        first(l) = p;
    }
}

void insertAfter(List &l , address prec , address p){
    if (first(l) == nil) {
        first(l) = p;
        next(p) = first(l);
    } else if(next(prec) == first(l)){
        insertLast(l ,p);
    } else  {
        next(p) = next(prec);
        next(prec) = p;
    }
}

void insertLast(List &l , address p) {
    if (first(l) == nil) {
        first(l) = p;
        next(p) = first(l);
    } else {
        address q = first(l);
        while (next(q) != first(l)){
            q = next(q);
        }
        next(p) = first(l);
        next(q) = p;
    }
}

void deleteFirst(List &l , address &p) {
    address q = first(l);
    if (first(l) != nil) {
        if (next(q) == first(l)) {
            first(l) = nil;
        } else {
            while (next(q) != first(l)) {
                q = next(q);
            }
            p = first(l);
            first(l) = next(p);
            next(p) = nil;
            next(q) = first(l);
        }
    } else {
        cout << "List sudah kosong" << endl;
    }
}

void deleteAfter(List &l , address prec , address &p){
   p = first(l);
   if (first(l) != nil){
        if (first(l)->next == first(l)){
            first(l) = nil;
        } else
         if (next(prec) == first(l)) {
            deleteFirst(l , p);
            } else {
            p = next(prec);
          	next(prec) = next(p);

            next(p) = nil;
            }
    } else {
        cout << "List sudah kosong" << endl;
    }
}

void deleteLast(List &l , address &p){
    if (first(l) != nil) {
        if (first(l)->next == first(l)) {
            first(l) = nil;
        } else {
            address q = first(l);
            while(next(next(q))!= first(l)){
                q = next(q);
            }
            p = next(q);
            next(q) = first(l);
            next(p) = nil;
        }
    }
}

address findElm(List l , infotype x) {
    if (first(l) == nil) {
        return nil;
    } else {
        address p = first(l);
        while ( p != nil && info(p) != x){
            p = next(p);
        }
        if ( p == nil) {
            return NULL;
        } else {
            return p;
        }
    }
}
void printInfo(List l){
    address p = first(l);
    if (first(l) != nil) {
        do {
            cout << info(p) << endl;
            p = next(p);
        } while (p != first(l));
    } else {
        cout << "List kosong";
    }
}

/*void clone(List l , List &m , List &n){
    address newP, newQ;
    address p = first(l);
    int i = 0;
    do {
        newP = findElm(l,10);
        insertFirst(m ,newP);
        p = next(p);
    } while(p != first(l));
}*/

address salin(List l) {
    if (first(l) == NULL) return NULL;
    address p = new elmList;
    info(p) = info(l);
    //result->info = List->info;
    next(p) = salin(next(l))
    //8result->next = salin(List->next);
    return result;
}
