#include <iostream>
#include <string>
#include "carwash.h"
#include <string.h>

using namespace std;


void createList(list &l){
	first(l) = nil;
};

void dealokasi(address p){
	delete p;
};

address alokasi(infoType x){
	address p;
	p = new elmList;

	info(p) = x;
	next(p) = nil;
	return p;
};

void insertFirst(list &l , address p){
	if(first(l) == nil){
		first(l) = p;
	}
	else {
		next(p) = first(l);
		first(l) = p;
	}
};

void insertLast(list &l , address p){
	address q;
	q = first(l);
	while (next(q) != nil){
		q = next(q);
	}
	next(q) = p ;
};

void insertAfter(address prec , address p){
	next(p) = next(prec);
	next(prec) = p;
};

void deleteFirst(list &l , address p){
	if (next(first(l)) == nil) {
		first(l) = nil;
	} else {
		p = first(l);
		first(l) = next(p);
		next(p) = nil;
	}
	dealokasi(p);
};

void deleteLast(list &l , address p){
	address q;
	q = first(l);

	while(next(p) != nil) {
		q = p;
		p = next(p);
	}
	next(q) = nil;
	dealokasi(p);
};

void deleteAfter(address prec , address &p){
	next(prec) = next(p);
	next(p) = nil;
	dealokasi(p);
};

address searchData(list l , infoType x){
	address p;
	p = first(l);

	while ( p != nil) {
		if (strcmp(info(p).noPol , x.noPol) == 0) {
			break;
		}
		p = next(p);
	}
	return p;
};

address searchDataBefore(list l , infoType x){
	address p;
	p = first(l);

	while (p != nil) {
		if (strcmp(info(next(p)).noPol , x.noPol) == 0){
			break;
		}
	}
	return p ;
};

void updateData(address p , infoType y){
	info(p) = y;
};

void printInfo(list l){
	address p;
	p = first(l);
	while ( p != nil) {
		cout << "Nomor Polisi : " << info(p).noPol << endl;
		cout << "Merk Mobil : " << info(p).merkMobil << endl;

		p = next(p);
	}

};
