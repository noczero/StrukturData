#include <iostream>
#include "singlelist.h"
using namespace std;

int main()
{
    //dealokasi(P1);
    List L;
    address P1 = NULL;
    dealokasi(P1);

    createList(L);
    insertFirst(L,P1);

    cout << "...1..." <<endl;
    printInfo(L);

    cout << "...2..." << endl;
    deleteFirst(L,P1);
    deleteLast(L,P1);

    cout << "...3..." << endl;
    P1 = alokasi(10);
    insertFirst(L,P1);

    P1 = alokasi(20);
    insertFirst(L,P1);

    printInfo(L);

    cout << "...4..." << endl;
    P1 = alokasi(6);
    insertFirst(L,P1);

    P1 = alokasi(30);
    insertFirst(L,P1);

    printInfo(L);

    cout << "...5..." << endl;
    P1 = findElm(L,20);
    cout << "info P1 = " << info(P1) << endl;
    cout << "P1 = " << P1 << endl;

    cout << "...6..." << endl;
    P1 = findElm(L,13);
    cout << "P1 = " << P1 << endl;

    cout << "...7..." << endl;
    deleteLast(L,P1);

    printInfo(L);

    cout << "...8..." << endl;
    cout << "info P1 = " << info(P1) << endl;
    cout << "P1 = " << P1 << endl;

    cout << "...9..." << endl;
    dealokasi(P1);
    cout << "P1 = " << P1 << endl;

    cout << "...10..." << endl;
    deleteFirst(L,P1);
    insertLast(L,P1);
    printInfo(L);

    cout << "...11..." << endl;
    deleteLast(L,P1);
    cout << "info P1 = " << info(P1) << endl;

    cout << "...12..." << endl;
    dealokasi(P1);
    deleteLast(L,P1);
    dealokasi(P1);
    deleteLast(L,P1);
    dealokasi(P1);
    printInfo(L);

    menu(L,P1);

    dealokasi(P1);
    return 0;
}
