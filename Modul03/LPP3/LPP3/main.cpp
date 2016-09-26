#include <iostream>
#include "singlelist.h"
using namespace std;

int main()
{
    List L;
    address P1 = NULL;
    dealokasi(P1);

    createList(L);

    menu(L,P1);
    dealokasi(P1);
    return 0;
}
