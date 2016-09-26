#include <iostream>
#include "singlelist.h"
using namespace std;

void createList(List &L){
    first(L) = Nil;
}

address alokasi (infotype x){
    address P = new ElmList;
    info(P) = x;
    next(P) = Nil;
    return P;
}

void dealokasi(address &P){
    delete P;
}

void insertFirst(List &L, address P){
    if (first(L) == Nil){
        first(L) = P;
    } else {
        next(P) = first(L);
        first(L) = P;
    }
}

void insertLast(List &L, address P){
    if (first(L) == Nil){
        first(L) = P;
    } else {
        address Q = first(L);
        while (Q->next != Nil){
            Q = Q->next;
        }
        Q->next = P;
    }
}

address findElm(List &L, infotype x){
    address P = first(L);
    while (next(P) != Nil){
        if (info(P) == x){
            cout<<info(P)<<endl;
            P = next(P);
        } else {
            P = next(P);
        }
    }
    return P;
}

void deleteFirst(List &L, address &P){
    if (first(L) != Nil){
        P = first(L);
        if (next(P) == Nil){
            first(L) = Nil;
        } else {
            first(L) = next(P);
            next(P) = Nil;
        }
    } else
    first(L) = Nil;
}
void deleteLast(List &L, address &P){
    if (first(L) != Nil){
        address Q = first(L);
        if (Q->next == Nil){
            first(L) = Nil;
        } else {
            while ((Q->next)->next != Nil){
                Q = Q->next;
            }
            P = Q->next;
            Q->next = Nil;
        }
    }
    else {
        cout << "List telah kosong" << endl;
    }
}
void printInfo(List L){
    address P = first(L);
    while (P != Nil){
        cout<< "Data : " << info(P)<<endl;
        P = next(P);
    }
}

void menu(List &L, address &P){
    int pilih , cari , data;
    do {
        cout<<endl;
        cout<<"1. Input Data"<<endl;
        cout<<"2. Cari Data"<<endl;
        cout<<"3. Tampil List"<<endl;
        cout<<"4. Keluar"<<endl;
        cout<<"Pilih Menu ";
        cin>>pilih;
        switch (pilih){
        case 1:
            cout << "Masukkan Data : ";
            cin >> data;
            P = alokasi(data);
            insertFirst(L,P);
            break;
        case 2:
            cout<<"Cari Data ke- : ";
            cin>>cari;
            P = findElm(L,cari);
            cout << "info P = " << info(P) << endl;
            cout << "P = " << P << endl;
            break;
        case 3:
            printInfo(L);
            break;
        case 4:
            cout<<"Keluar "<<endl;
            break;
        }
    } while (pilih != 4);
}
