#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstring>
#include "carwash.h"

using namespace std;

int main(){
	infoType Mobil;
	list l;
	createList(l);
	strcpy(Mobil.noPol, "D 123 EF");
	strcpy(Mobil.merkMobil, "Toyota");

	address p;

	p = alokasi(Mobil);
	insertFirst(l , p);
	printInfo(l);
	//insertAfter(l , p);
	return 0;
}