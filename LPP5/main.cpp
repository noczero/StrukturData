#include <iostream>
#include "circularlist.h"

using namespace std;

int main()
{
    List L,L2,L3;
    address P1 = nil;
    address P2 = nil;
    createList(L);
    createList(L2);
    createList(L3);

    cout << endl << "Coba Insert First dan Last" << endl;
    P1 = alokasi(10);
    insertFirst(L,P1);
    P1 = alokasi(10);
    insertLast(L , P1);
    P1 = alokasi(20);
    insertFirst(L , P1);
    P1 = alokasi(20);
    insertFirst(L, P1);
    printInfo(L);


    clone(L , L2, L3);
     cout<< endl;
    printInfo(L2);
    cout<< endl;
    printInfo(L3);
 /*   cout << endl << "Coba Insert After" << endl;
    P1 = findElm(L,5);
    P2 = alokasi(99);
    insertAfter(L, P1 , P2);

    P1 = findElm(L, 13);
    P2 = alokasi(70);
    insertAfter(L , P1 , P2);
    printInfo(L);

    cout << endl << "Coba Delete After" << endl;
    P1 = findElm(L, 99);
    deleteAfter(L , P1 , P2);
    dealokasi(P2);

    P1 = findElm(L , 20);
    deleteAfter(L , P1 , P2);
    dealokasi(P2);
    printInfo(L);

    cout << endl << "Coba Delete First dan Last" << endl;
    deleteFirst( L , P1);
    dealokasi(P1);

    deleteLast(L, P1);
    dealokasi(P1);
    printInfo(L);
*/

    return 0;
}
