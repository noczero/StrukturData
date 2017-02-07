#include <iostream>
#include "doublelist.h"
using namespace std;

int main()
{
    List L1, L2;
    kendaraan k1, k2, k3;
    address P;
    createList(L1);
    createList(L2);

    k1.nopol = "D001DD";
    k1.warna = "Merah" ;
    k2.nopol = "BK1300QK";
    k2.warna = "Hitam" ;
    k3.nopol = "D6798SAX";
    k3.warna = "Hitam" ;

    P = alokasi(k2);
    insertFirst(L1 , P);

    P = alokasi(k1);
    insertLast(L2,P);

    P = alokasi(k1);
    insertLast(L1,P);

    P = alokasi(k3);
    insertFirst(L2 , P);

    printInfo(L1);
    cout << endl;
    printInfo(L2);

    return 0;
}
