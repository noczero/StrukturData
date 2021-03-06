#include "zeroReservation.h"
#include <cstdlib>

/*----------  Function & Procedure  ----------*/

/*===================================
=            Create List            =
===================================*/
void createListPlane(plane &l){
	l.first = NULL;
	l.last = NULL;
}
void createListSchedules(schedules &l) {
	l.first = NULL;
	l.last = NULL;
}
void createListPassenger(passenger &l){
	l.first = NULL;
}

void createListRelasi(listRelasi &l) {
    l.first = NULL;
    l.last = NULL;
}

void createListRelasi2(listRelasi2 &l) {
	l.first = NULL;
}

/*=====  End of Create List  ======*/

/*==================================
=            Alocattion            =
==================================*/
addressSchedules alokasiSch(dataSchedules x){
	addressSchedules p;
	p = new elmSchedules;
	p->info = x;
	p->next = NULL;
	p->prev = NULL;

    createListRelasi(p->child);
	return p;
}

addressPlane alokasiPlane(dataPlane x){
	addressPlane p;
	p = new elmPlane;
	p->info = x;
	p->next = NULL;
	p->prev = NULL;
    createListRelasi2(p->child);
	return p;
}

addressPassenger alokasiPassenger(dataPassenger x){
	addressPassenger p;
	p = new elmPassenger;
	p->info = x;
	p->next = NULL;
	return p;
}

addressRelasi alokasiRelasi(addressPlane c) {
    addressRelasi p = new elmListRelasi;
    info(p) = c;
    next(p) = NULL;

    return p;
}

addressRelasi2 alokasiRelasi2(addressPassenger c){
	addressRelasi2 p = new elmListRelasi2;
	p->info = c;
	p->next = NULL;

	return p;
}
/*=====  End of Alocattion  ======*/




/*==============================
=            Insert            =
==============================*/
/*----------  Option Insert  ----------*/

/*----------  Schedules  ----------*/
void insertSchedulesMain(schedules &l){
	dataSchedules x;
	addressSchedules p;

	char pilih;
	do {
		addDataSchedules(l,x);

		p = alokasiSch(x);
		insertFirstSch(l , p);
		cout << "Success... \n Masukkan data lagi ? (y/n) ";
		cin >> pilih;
		system("CLS");
	} while (pilih != 'n' && pilih != 'N');
}

void addDataSchedules(schedules l ,dataSchedules &x) {
	cout << "========================================" << endl;
	cout <<	"=            Zero Reservation          =" << endl;
	cout << "========================================" << endl;
	cout << "# Input Schedules Data  " << endl;
	pilihbalik:
	cout << "> Schedules ID          : " ; cin >> x.schID;

	if (checkSchedulesID( l , x.schID)) {
			cout << " -- ID Already exist -- ";
			cout << "masukkan ID lagi" << endl;
			goto pilihbalik;
	}
	cout << "> Date (DD/MM/YYYY)     : "; cin >> x.date;
		if(cin.fail())
        {
          cin.clear();
          cin.ignore();
          cout << "Error, Input tipe datanya salah.";
        }
}
void insertFirstSch(schedules &l , addressSchedules p){
    if (l.first == NULL) {
        l.first = p;
        l.last = p;
    } else {
        p->next = l.first;
        l.first->prev = p;
        l.first = p;
    }
}


void insertLastSch(schedules &l , addressSchedules p){
    if (l.first == NULL ){
        l.first = p;
        l.last = p;
    } else {
        p->prev = l.last;
        l.last->next = p;
        l.last = p;
    }
}

/*----------  Plane  ----------*/
void addDataPlane(plane l , dataPlane &x) {

	system("CLS");
	cout << endl;
	cout << "========================================" << endl;
	cout <<	"=            Zero Reservation          =" << endl;
	cout << "========================================" << endl;
	cout << "# Input Planes Data  " << endl;
	pilihbalikID:
	cout << "> Plane ID  :" ; cin >> x.planeID;

	if (checkPlaneID( l , x.planeID)) {
			cout << " -- ID Already exist -- ";
			cout << "masukkan ID lagi" << endl;
			goto pilihbalikID;
	}

	cout << "> Type     :"; cin >> x.type;
	cout << "> Route    :"; cin >> x.route;
		pilihbalik:
	cout << "> Price    :"; cin >> x.price;
		 if(cin.fail())
         {
           cin.clear();
           cin.ignore();
           cout << "Error, Input tipe datanya salah." << endl;
          goto pilihbalik;
         }
         pilihbalik2:
	cout << "> Capacity :"; cin >> x.capacity;

	if(cin.fail())
        {
          cin.clear();
          cin.ignore();
          cout << "Error, Input tipe datanya salah." << endl;
          goto pilihbalik2;

        }

}

void insertPlaneMain(plane &l) {
	dataPlane x;
	addressPlane p;

	char pilih;
	do {
		addDataPlane(l,x);
		p = alokasiPlane(x);
		insertFirstPlane( l , p);
		cout << "Success... \n Masukkan data lagi ? (y/n) ";
		cin >> pilih;
		system("CLS");
	} while (pilih != 'n' && pilih != 'N');

}

void insertFirstPlane(plane &l , addressPlane p){
    if (l.first == NULL) {
        l.first = p;
        l.last = p;
    } else {
        p->next = l.first;
        l.first->prev = p;
        l.first = p;
    }
}

void insertLastPlane(plane &l , addressPlane p){
	if (l.first == NULL) {
		l.first = p;
		l.last = p;
	} else {
		p->prev = l.last;
		l.last->next = p;
		l.last = p;
	}
}

/*----------  Passenger  ----------*/
void insertPassengerMain(passenger &l) {
	dataPassenger x;


	char pilih;
	do {
		addDataPassenger( l , x);
		addressPassenger p = alokasiPassenger(x);
		insertFirstPas(l,p);
		cout << "Success... \n Masukkan data lagi ? (y/n) ";
		cin >> pilih;
		system("CLS");
	} while (pilih != 'n' && pilih != 'N');
}

void addDataPassenger(passenger l , dataPassenger &x) {
	cout << endl;
	cout << "========================================" << endl;
	cout <<	"=            Zero Reservation          =" << endl;
	cout << "========================================" << endl;
	cout << "# Input Passenger Data" << endl;
	pilihbalikID:
	cout << "> Passenger ID  : " ; cin >> x.passengerID;

	if (checkPassengerID( l , x.passengerID)) {
			cout << " -- ID Already exist -- ";
			cout << "masukkan ID lagi" << endl;
			goto pilihbalikID;
	}

	cout << "> Name          : "; cin >> x.name;
	cout << "> Username      : "; cin >>x.username;
	cout << "> Password      :"; cin >> x.password;
	pilihbalik:
	cout << "> Age           : "; cin >> x.age;
    if(cin.fail())
        {
          cin.clear();
          cin.ignore();
          cout << "Error, Input tipe datanya salah.";
        goto pilihbalik;
        }
	cout << "> Gender       : "; cin >> x.gender;
	cout << "> Address      : "; cin >> x.address;

}
void insertFirstPas(passenger &l, addressPassenger p){
    if (l.first == NULL) {
        l.first = p;
    } else {
        p->next = l.first;
        l.first = p;
    }
}


void insertLastPas(passenger &l , addressPassenger p) {
    if (l.first == NULL) {
        l.first = p;
    } else {
        addressPassenger q = l.first;
        while (q->next != NULL) {
            q = q->next;
        }
        q->next = p;
    }
}

/*----------  Relasi  ----------*/
void insertFirst(listRelasi &l, addressRelasi p){
    if (l.first == NULL) {
        l.first = p;
        l.last = p;
    } else {
        p->next = l.first;

        l.first = p;
         l.first->prev = p;
    }
}

void insertLast(listRelasi &l, addressRelasi p){
	if (l.first == NULL) {
		l.first = p;
		l.last = p;
	} else {
		p->prev = l.last;
		l.last->next = p;
		l.last = p;
	}
}

/*----------  #Relasi2  ----------*/
void insertFirstR2(listRelasi2 &l, addressRelasi2 p){
    if (l.first == NULL) {
        l.first = p;
    } else {
        p->next = l.first;
        l.first = p;
    }
}
void insertLastR2(listRelasi2 &l, addressRelasi2 p){
	if (l.first == NULL) {
		l.first = p;
	} else {
		addressRelasi2 q = l.first;
        while (q->next != NULL) {
            q = q->next;
        }
        q->next = p;
	}
}
/*=====  End of Insert  ======*/

/*----------  add  to relasi ---------- */
void addJadwaltoPlane(schedules &sch , plane &pln ) {
        addressSchedules p;
        addressPlane q;
        addressRelasi r,s;

        string idPlane , idSchedules;
        char pilih;
             system("CLS");
       	cout << endl;
		cout << "========================================" << endl;
		cout <<	"=            Zero Reservation          =" << endl;
		cout << "========================================" << endl;

        do {
            cout << "Input ID Jadwal \t:"; cin >> idSchedules;
            cout << "Input ID Pesawat\t: "; cin >> idPlane;

            p = findElmSchedules( sch , idSchedules);
            if (p == NULL) {
                cout << "ID Jadwal tidak ditemukan" << endl;
            } else {
                q = findElmPlane( pln , idPlane);
                if (q == NULL) {
                    cout << "ID Pesawat tidak ditemukan" << endl;
                } else {
                    r = alokasiRelasi(q);
                    insertFirst(p->child , r);
                    cout << "\nSuccess... ";
                    cout << info(p).schID << " --- " << info(q).planeID << endl;
                }

                if (p == NULL && q == NULL)
                	cout << "\nFailed...";
            }
           	cout << "Lakukan relasi data lagi ? (y/n) ";
			cin >> pilih;
        } while (pilih != 'n' && pilih != 'N');
}

void pesanPenerbangan(plane &l , addressPassenger psgr) {
       	cout << endl;
		cout << "========================================" << endl;
		cout <<	"=            Zero Reservation          =" << endl;
		cout << "========================================" << endl;

		if (l.first == NULL) {
			cout << " -- no plane --" << endl;
		} else {

			string ID;
			cout << " Masukan ID Pesawat yang ingin dipesan : " ;
			cin >> ID;

			// if (checkRelasi2(l , ID)) {
			// 	cout << " -- ID Already Existing -- " << endl;
			// 	getch();
			// }
				addressPlane p = findElmPlane( l , ID);
				if (p == NULL) {
					cout << " -- Pesawat tidak ditemukan --" << endl;
				} else {

					//cout << checkRelasi(p , ID);
					if (checkRelasi2(p->child, psgr->info.passengerID)) {
					cout << " -- Anda sudah memesan " << p->info.planeID << " -- "<< endl;
					} else {

					addressRelasi2 r;
					r = alokasiRelasi2(psgr);

					p->info.capacity--;
					insertFirstR2(p->child , r);

					cout << " -- Success.. \n " << endl;
					cout <<"Selamat.. " << psgr->info.name << ", Pesawat dengan ID " << p->info.planeID << " berhasil dipesan " << endl;

				}
			}
		}
		getch();
}

/*=====  End of add  ======*/


/*==============================
=            Delete            =
==============================*/
/*----------  schedules  ----------*/
void deleteFirstSch(schedules &l) {
    addressSchedules p;


    if(first(l) == NULL)
    {
        cout << "List sudah kosong" << endl;
    }
    else
    {
        p = first(l);
        if ((first(l) != NULL)&&(next(first(l))==NULL))
        {
            first(l) = NULL;
            last(l) = NULL;
            delete p;
        }
        else
        {
            prev(next(p)) = NULL;
            first(l) = next(p);
            next(p) = NULL;
            delete p;
        }
    }

}

void deleteLastSch(schedules &l){
    addressSchedules p;
    if (first(l) != NULL) {
         if (first(l) == last(l)) {
            first(l) == NULL;
            last(l) == NULL;
         } else {
            p = last(l);
            last(l) = last(l)->prev;
            prev(p) = NULL;
            last(l)->next = NULL;
             delete p;
         }

    } else {
        cout << "List sudah kosong" << endl;
    }

}
void deleteSchbyID(schedules &l) {
    addressSchedules p;

    string id;
	cout << "========================================" << endl;
	cout <<	"=            Zero Reservation          =" << endl;
	cout << "========================================" << endl;

    if (l.first == NULL) {
        cout << " -- Tidak bisa menghapus List.. \n List Schedules kosong... --";
    } else {
        char pilih;
        do {
            cout << endl;
            cout << "Masukkan ID yang akan didelete : " ;
            cin >> id;

            p = findElmSchedules(l , id);

            if (p == NULL) {
                cout << "-- ID Jadwal tidak ditemukan --" << endl;
            } else {
                cout << info(p).schID;
                if (next(first(l)) == NULL) {
                    first(l) = NULL;
                    last(l) = NULL;

                    delete p;
                } else {
                    if (p == first(l) && next(p) != NULL ){
                        deleteFirstSch(l);
                    } else    if (next(p) == NULL && (prev(p) != NULL)) {
                        deleteLastSch(l);
                    }
                    else {
                        addressSchedules q = p->prev;
                        q->next = p->next;
                        p->next->prev = q;
                        p->next = NULL;
                        p->prev = NULL;

                        delete p;
                    }
                }
                cout << " Berhasil dihapus..." << endl;
            }
            cout << "Hapus lagi ? (y/n) ";
            cin >> pilih;
        } while (pilih != 'n' && pilih != 'N');
    }
}


void deleteRelasibyID(schedules &l){
     addressSchedules p;
     addressRelasi q , r;

    string id;
    system("CLS");
	cout << "========================================" << endl;
	cout <<	"=            Zero Reservation          =" << endl;
	cout << "========================================" << endl;

	if (l.first == NULL){
        cout << " -- Tidak bisa menghapus List.. \n List Schedules kosong... --" ;
	} else {
        char pilih;
        do {
            cout << endl;
            pilihbalik:
            cout << "Masukkan ID jadwal yang akan didelete : " ;
            cin >> id;

            p = findElmSchedules(l , id);

            if ( p == NULL) {
                cout << "-- ID Tidak ada -- " << endl;
                goto pilihbalik;
            }

            cout << "Masukkan ID Pesawawt yang akan didelete : ";
            string planeID;
            cin >> planeID;

            r = findElmRelasi(p->child , planeID);
            //q = p->child.first;

            if (r == NULL) {
                cout << "-- ID Jadwal tidak ditemukan --" << endl;
            } else {
                cout << r->info->info.planeID;
                if (r->next == NULL) {
                    p->child.first= NULL;
                    p->child.last = NULL;

                   // delete p;
                } else {
                    if (r == p->child.first && r->next != NULL ){
                        deleteFirstRelasi(p->child);
                    } else    if (next(r) == NULL && (prev(r) != NULL)) {
                        deleteLastRelasi(p->child);
                    }
                    else {
                        addressRelasi q = r->prev;
                        q->next = r->next;
                        r->next->prev = q;
                        r->next = NULL;
                        r->prev = NULL;

                        delete r;
                    }
                }
                cout << " Berhasil dihapus..." << endl;
            }
            cout << "Hapus lagi ? (y/n) ";
            cin >> pilih;
        } while (pilih != 'n' && pilih != 'N');
	}
}

void deleteRelasi2byID(plane &l){
     addressPlane p;
     addressRelasi2 q , r;

    string id;
    system("CLS");
    cout << endl;
	cout << "========================================" << endl;
	cout <<	"=            Zero Reservation          =" << endl;
	cout << "========================================" << endl;

   	char pilih;
   	if (l.first == NULL) {
        cout << "  -- Tidak bisa menghapus List.. \n List Pesawat kosong... --" << endl;
   	} else {
        do {
            cout << endl;
            pilihbalik:
            cout << "Masukkan ID Pesawat yang akan dibatalkan : " ;
            cin >> id;

            p = findElmPlane(l , id);

            if ( p == NULL) {
                cout << "-- ID Tidak ada -- " << endl;
                goto pilihbalik;
            }

            cout << "Masukkan ID Penumpang yang akan dibatalkan : ";
            string passID;
            cin >> passID;

            r = findElmRelasi2(p->child , passID);
            //q = p->child.first;

            if (r == NULL) {
                cout << "-- ID Penumpang tidak ditemukan --" << endl;
            } else {
                cout << r->info->info.passengerID;
                if (r->next == NULL) {
                    p->child.first= NULL;

                } else {
                    if (r == p->child.first && r->next != NULL ){
                        deleteFirstR2(p->child);
                    } else    if (next(r) == NULL) {
                        deleteLastR2(p->child);
                    }
                    else {
                        addressRelasi2 q = p->child.first;

                        while (q->next != r) {
                            q = q->next;
                        }
                        q->next = r->next;
                        r->next = NULL;
                        delete r;
                    }
                }
                cout << " Berhasil dihapus..." << endl;
            }
            cout << "Hapus lagi ? (y/n) ";
            cin >> pilih;
        } while (pilih != 'n' && pilih != 'N');
   	}
}

void deleteFirstRelasi(listRelasi &l) {
     addressRelasi p;
     if(first(l) == NULL)
    {
        cout << "List sudah kosong" << endl;
    }
    else
    {
        p = first(l);
        if ((first(l) != NULL)&&(next(first(l))==NULL))
        {
            first(l) = NULL;
            last(l) = NULL;
            delete p;
        }
        else
        {
            prev(next(p)) = NULL;
            first(l) = next(p);
            next(p) = NULL;

            delete p;
        }
    }
}

void deleteLastRelasi(listRelasi &l){
    addressRelasi p;
    if (first(l) != NULL) {
         if (first(l) == last(l)) {
            first(l) == NULL;
            last(l) == NULL;
         } else {
            p = last(l);
            last(l) = last(l)->prev;
            prev(p) = NULL;
            last(l)->next = NULL;
             delete p;
         }

    } else {
        cout << "List sudah kosong" << endl;
    }
}

void deleteFirstR2(listRelasi2 &l){
    if (l.first != NULL) {
        addressRelasi2 P = first(l);
        if (next(P) == NULL){
            first(l) = NULL;
        } else {
            first(l) = next(P);
            next(P) = NULL;
        }
    	delete P;
    } else {
        cout << "List sudah kosong" << endl;
    }
}

void deleteLastR2(listRelasi2 &l) {
    if (l.first != NULL ){
        addressRelasi2 Q = first(l);
        if (Q->next == NULL){
            first(l) = NULL;
        } else {
        	addressRelasi2 P;
            while ((Q->next)->next != NULL){
                Q = Q->next;
            }
            P = Q->next;
            Q->next = NULL;
            delete P;
        }
    }
}


/*----------  plane  ----------*/
void deleteFirstPlane(plane &l){
  addressPlane p;

    if(first(l) == NULL)
    {
        cout << "List sudah kosong" << endl;
    }
    else
    {
        p = first(l);
        if ((first(l) != NULL)&&(next(first(l))==NULL))
        {
            first(l) = NULL;
            last(l) = NULL;
            delete p;
        }
        else
        {
            prev(next(p)) = NULL;
            first(l) = next(p);
            next(p) = NULL;
            delete p;
        }
    }

}

void deleteLastPlane(plane &l){
    addressPlane p;
    if (first(l) != NULL) {
         if (first(l) == last(l)) {
            first(l) == NULL;
            last(l) == NULL;
         } else {
            p = last(l);
            last(l) = last(l)->prev;
            prev(p) = NULL;
            last(l)->next = NULL;
             delete p;

         }

    } else {
        cout << "List sudah kosong" << endl;
    }
}

void deletePlanebyID(plane &l){
    addressPlane p;
    string id;
	cout << "========================================" << endl;
	cout <<	"=            Zero Reservation          =" << endl;
	cout << "========================================" << endl;

   	char pilih;
    if ( l.first == NULL) {
        cout << "  -- Tidak bisa menghapus List.. \n List Pesawat kosong... -- " << endl;
    } else {
        do {
            cout << "Masukkan ID Pesawat yang akan didelete : " ;
            cin >> id;

            p = findElmPlane(l , id);

            if (p == NULL) {
                cout << " -- ID Pesawat tidak ditemukan -- " << endl;
            } else {
                cout << info(p).planeID;
                if (next(first(l)) == NULL) {
                    first(l) = NULL;
                    last(l) = NULL;

                    delete p;
                } else {
                     if (p == first(l) && next(p) != NULL ){
                        deleteFirstPlane(l);
                    } else if (next(p) == NULL && prev(p) != NULL) {
                        deleteLastPlane(l);
                    } else {
                        addressPlane q = p->prev;
                        q->next = p->next;
                        p->next->prev = q;
                        p->next = NULL;
                        p->prev = NULL;
                        delete p;
                    }
                }
             cout << " Berhasil dihapus..." << endl;
            }
            cout << "Hapus lagi ? (y/n) " ;
            cin >> pilih;
        } while (pilih != 'n' && pilih != 'N');
    }
}
void deletePlaneMain(plane &l);

/*----------  passenger  ----------*/
void deleteFirstPas(passenger &l){
	if (first(l) != NULL){
        addressPassenger P = first(l);
        if (next(P) == NULL){
            first(l) = NULL;
        } else {
            first(l) = next(P);
            next(P) = NULL;
        }
    	delete P;
    }
}

void deleteLastPas(passenger &l){
	if (first(l) != NULL){
        addressPassenger Q = first(l);
        if (Q->next == NULL){
            first(l) = NULL;
        } else {
        	addressPassenger P;
            while ((Q->next)->next != NULL){
                Q = Q->next;
            }
            P = Q->next;
            Q->next = NULL;
            delete P;
        }
	}
}

void deletePasbyID(passenger &l){

    addressPassenger p;
    string id;
	cout << "========================================" << endl;
	cout <<	"=            Zero Reservation          =" << endl;
	cout << "========================================" << endl;

	if (l.first == NULL) {
        cout << "-- Tidak ada List Passenger -- ";
	} else {
        char pilih;
        do {
            cout << "Masukkan ID Passanger yang akan didelete : " << endl;
            cin >> id;

             p = findElmPassenger(l , id);

            if (p == NULL) {
                cout << " -- ID Passenger tidak ditemukan -- " << endl;
            } else {
                cout << info(p).passengerID;
                if (next(first(l)) == NULL) {
                    first(l) = NULL;

                    delete p;
                } else {
                    if (next(p) == NULL) {
                        deleteLastPas(l);
                    } else  if (p == first(l) && next(p) != NULL ){
                        deleteFirstPas(l);
                    } else {
                        addressPassenger q = l.first;

                        while(next(q) != p) {
                            q = next(q);
                        }

                        next(q) = next(p);
                        next(p) = NULL;
                        delete p;
                    }
                }
                cout << " Berhasil dihapus..." << endl;
            }

            cout << "Hapus lagi? (y/n) ";
            cin >> pilih;
        } while (pilih != 'N' && pilih != 'n');

	}
}
void deletePasMain(passenger &l);


/*=====  End of Delete  ======*/




/*========================================
=            Find & Searching            =
========================================*/
addressPlane findElmPlane(plane l , string planeID){
    if (first(l) == NULL) {
        return NULL;
    }
    else {
        addressPlane p = first(l);
        while ( p != NULL && info(p).planeID != planeID) {
            p = next(p);
        }
        if (p == NULL) {
            return NULL;
        } else {
            return p;
        }
    }
}
addressSchedules findElmSchedules(schedules l, string schID){
    if (first(l) == NULL) {
        return NULL;
    }
    else {
        addressSchedules p = first(l);
        while ( p != NULL && info(p).schID != schID) {
            p = next(p);
        }
        if (p == NULL) {
            return NULL;
        } else {
            return p;
        }
    }
}

addressPlane findTypePlane(plane l , dataPlane x) {
    addressPlane p ;
    if (l.first == NULL) {
        return NULL;
    } else {
        p = l.first;

        while (p!= NULL && p->info.type != x.type){
            p = next(p);
        }

        if (p == NULL) {
            return NULL;
        } else {
            return p;
        }
    }
}

addressPassenger findElmPassenger(passenger l , string passengerID){
    if (l.first == NULL) {
        return NULL;
    } else {
        addressPassenger p = l.first;

        while (p != NULL) {

            if (passengerID == info(p).passengerID) {
                return p;
            } else {
                p = next(p);
            }
        }

        if (p == NULL) {
            return NULL;
        } else {
            return p;
        }
    }
}

addressRelasi findElmRelasi(listRelasi l , string  planeID) {
    if (l.first == NULL) {
        return NULL;
    } else {
        addressRelasi p = l.first;
        while (p != NULL && p->info->info.planeID != planeID) {
            p = p->next;
        }

        if (p == NULL) {
            return NULL;
        } else {
            return p;
        }
    }

}

addressRelasi2 findElmRelasi2(listRelasi2 l , string  passID) {
    if (l.first == NULL) {
        return NULL;
    } else {
        addressRelasi2 p = l.first;
        while (p != NULL && p->info->info.passengerID != passID) {
            p = p->next;
        }

        if (p == NULL) {
            return NULL;
        } else {
            return p;
        }
    }

}


/*=====  End of Find & Searching  ======*/

/*=============================
=            #Print            =
=============================*/

void printInfoRelasi2(listRelasi2 l){
	addressRelasi2 p = l.first;
	cout << " \t -- Passenger --" << endl;
	int i = 1;

	while ( p != NULL) {
			cout << endl;
        	cout << "----------------------------" << endl;
            cout << " \t Passanger Data " << i << endl
                << "\t > ID      : " << p->info->info.passengerID << endl
                << "\t > Name    : " << p->info->info.name << endl
                << "\t > Age     : " << p->info->info.age << endl
                << "\t > Gender  : " << p->info->info.gender << endl
                << "\t > Address : " << p->info->info.address << endl;
            p = p->next;
            i++;

	}

}

void printPesanan(plane l , addressPassenger p){
	//addressPassenger p = l.first;
	system("CLS");
	cout << endl;
    cout << "========================================" << endl;
    cout <<	"=            Zero Reservation          =" << endl;
    cout << "========================================" << endl;
	cout << " === Passenger ID === " << endl;
	cout << " > ID Passenger  : " << p->info.passengerID << endl;
	cout << " > Nama \t : " << p->info.name << endl;
	cout << " > Gender \t : " << p->info.gender << endl;
	cout << " > Age \t\t : " << p->info.age << endl;
	cout << " > Address \t : " << p->info.address << endl;
	cout << "======================================" << endl;

    addressPlane pln;
     bool found = false;
    int i = 1;
    pln = l.first;
    addressRelasi2 q;
    while (pln != NULL) {
        q = pln->child.first;
        while (q != NULL) {

            if ( q->info->info.passengerID == p->info.passengerID) {
                cout << "Pesanan " << i << endl;
                cout << "--------------------------------------" << endl;
                cout << " > Plane ID \t : " << pln->info.planeID << endl;
                cout << " > Type \t : " << pln->info.type << endl;
                cout << " > Route \t : " << pln->info.route << endl;
                cout << " > Price \t : " << pln->info.price << endl;
                cout << " > Capacity \t : " << pln->info.capacity << endl;
                i++;
                found = true;
                break;
            } else if ( q == NULL ) {
                found = false;
            }
            q = q->next;
        }
        pln = pln->next;
    }


    if (!found)
        cout << "\t -- Tidak ada pesanan -- " << endl;

    getch();
}

void printInfoSchedules(schedules l) {
    addressSchedules p;
        system("CLS");
        cout << "========================================" << endl;
        cout <<	"=            Zero Reservation          =" << endl;
        cout << "========================================" << endl;
        cout << "===          Flight Schedules        ===" << endl;
    if (l.first != NULL) {
        p = l.first;
        int i = 1;
        while (p != NULL) {
            cout << endl;
        	cout << "----------------------------" << endl;
            cout << "Schedules Data " << i << endl
                << "ID \t: " << p->info.schID << endl
                << "Date \t: " << p->info.date << endl;
            p = p->next;
            i++;
        }
    } else {
        cout << "Data Jadwal tidak ada " << endl;
    }
}

void printInfoPlane(plane l){
    addressPlane p;
        system("CLS");
        cout << "========================================" << endl;
        cout <<	"=            Zero Reservation          =" << endl;
        cout << "========================================" << endl;
        cout << "===            Planes Lists          ===" << endl;
    if (l.first != NULL) {
        p = l.first;
        int i = 1;
        while (p != NULL) {
            cout << endl;
        	cout << "----------------------------" << endl;
            cout << "Planes Data " << i << endl
                 << "ID \t: " << p->info.planeID << endl
                << "Type \t: " << p->info.type << endl
                << "Route \t: " << p->info.route << endl
                << "Price \t: " << p->info.price << endl
                << "Capacity: " << p->info.capacity << endl;

            p = p->next;
            i++;
        }
    } else {
        cout << "Data pesawat tidak ada ";
    }
}

void printSch_Pln(schedules l) {
    addressSchedules p;
    if (l.first != NULL) {
        p = l.first;
        int i = 1;
        system("CLS");
        cout << endl;
        cout << "========================================" << endl;
        cout <<	"=            Zero Reservation          =" << endl;
        cout << "========================================" << endl;
        cout << "===         Schedules -- Plane       ===" << endl;
        while (p != NULL) {
            cout << endl;
        	cout << "========================================" << endl;
            cout << "Schedules Data " << i << endl
                << "ID \t: " << p->info.schID << endl
                << "Date \t: " << p->info.date << endl;

             	if (p->child.first == NULL) {
             		cout << " \n\t-- No Plane on "<< p->info.schID << " -- "  << endl;
            	 } else {
            		printInfoRelasi(p->child);
            	}

            p = p->next;
            i++;
        }
    } else {
        cout << "\t -- No Schedules List -- " << endl;
    }
}

void printInfoPassenger(passenger l) {
    addressPassenger p;
        system("CLS");
        cout << "========================================" << endl;
        cout <<	"=            Zero Reservation          =" << endl;
        cout << "========================================" << endl;
        cout << "===           Passenger Lists        ===" << endl;
    if (l.first != NULL) {
        p = l.first;
        int i = 1;
        while (p != NULL) {
            cout << endl;
        	cout << "----------------------------" << endl;
            cout << "Passanger Data " << i << endl
                << "ID \t: " << p->info.passengerID << endl
                << "Name \t: " << p->info.name << endl
                << "Age \t: " << p->info.age << endl
                << "Gender \t: " << p->info.gender << endl
                << "Address : " << p->info.address << endl;
            p = p->next;
            i++;
        }
    } else {
        cout << "Pessanger Data tidak ada" << endl;
    }

}


void printInfoRelasi(listRelasi l){
    addressRelasi p = l.first;
    cout << " \t -- PLANE -- " << endl;
    int i = 1;
    while (p != NULL) {
    	cout << "----------------------------" << endl;
		cout<< "\t Pesawat " << i << endl
        	<< "\t ID \t: " << p->info->info.planeID << endl
            << "\t Type \t: " << p->info->info.type << endl
            << "\t Route \t: " << p->info->info.route << endl
            << "\t Capacity  : " << p->info->info.capacity << endl
            << "\t Price \t: " << p->info->info.price << endl;
        p = p->next;
        i++;
    }
}

void printplane_passenger(plane l) {

    int i = 1;
    if (l.first == NULL) {
        cout << " \t -- No Passenger List --" << endl;
    } else {
        addressPlane p = l.first;
        //addressPassenger q;
        system("CLS");
        cout << endl;
        cout << "========================================" << endl;
        cout <<	"=            Zero Reservation          =" << endl;
        cout << "========================================" << endl;
        cout << "===         Plane -- Passenger       ===" << endl;
        while (p != NULL) {
            cout << endl;
            cout << "========================================" << endl;
            cout << "Planes Data " << i << endl
                << "ID \t: " << p->info.planeID << endl
                << "Type \t: " << p->info.type << endl
                << "Route \t: " << p->info.route << endl
                << "Price \t: " << p->info.price << endl
                << "Capacity: " << p->info.capacity << endl;

            if (p->child.first == NULL) {
            	cout << "\n \t-- No Passenger on " << p->info.planeID << " --" << endl;
            } else {

            	printInfoRelasi2(p->child);
            }
            i++;
            p = p->next;
        }

    }
}





/*=====  End of Print  ======*/


/*----------  Menu  ----------*/


bool loginAdmin(string username , string password){
    if (username == "admin" && password == "admin")
        return true;
    else
        return false;
}

bool loginPassanger(passenger pas ,string ID, string username , string password){
        addressPassenger p = findElmPassenger(pas , ID);
        if (p != NULL) {
            if (p->info.username == username && p->info.password == password)
                return true;
        } else
        return false;
}

bool login = false;

void menuDelete(schedules &sch , plane &pln , passenger &pas){
	int pilih;
    pilihbalik:
    system("CLS");
    cout << "========================================" << endl;
    cout <<	"=            Zero Reservation          =" << endl;
    cout << "========================================" << endl;
    cout << " 1. Mengapus Jadwal Penerbangan " << endl;
    cout << " 2. Mengapus Data Pesawat " << endl;
    cout << " 3. Mengapus Data Passenger" << endl;
    cout << " 99. Exit" << endl;
    cout << "\nPilih Menu" ;
    cin >> pilih;

    if(cin.fail())
        {
          cin.clear();
          cin.ignore();
          cout << "Error, Input hanya angka...";
          goto pilihbalik;
          // menuTambah( sch, pln , pas);
        } else {

    switch (pilih) {
        case 1 :
            system("CLS");
            deleteSchbyID(sch);
        break;
        case 2 :
            system("CLS");
            deletePlanebyID(pln);
        break;
        case 3 :
            system("CLS");
         	deletePasbyID(pas);
        break;
        case 99 :
            menuAdmin(sch,pln,pas);
        break;
        default :
            cout << "Menu tidak tersedia..." << endl;
            getch();
            goto pilihbalik;
        }

    }
}

void menuEdit(schedules &sch , plane &pln , passenger &pas) {
	int pilih;
    pilihbalik:
    system("CLS");
    cout << "========================================" << endl;
    cout <<	"=            Zero Reservation          =" << endl;
    cout << "========================================" << endl;
    cout << " 1. Mengedit Jadwal Penerbangan " << endl;
    cout << " 2. Mengedit Data Pesawat " << endl;
    cout << " 3. Mengedit Data Passenger" << endl;
    cout << " 99. Exit" << endl;
    cout << "\nPilih Menu" ;
    cin >> pilih;

    if(cin.fail())
        {
          cin.clear();
          cin.ignore();
          cout << "Error, Input hanya angka...";
          goto pilihbalik;
          // menuTambah( sch, pln , pas);
        } else {

    switch (pilih) {
        case 1 :
            system("CLS");
            editSchedules(sch);
        break;
        case 2 :
            system("CLS");
            editPlane(pln);
        break;
        case 3 :
            system("CLS");
         	editPassenger(pas);
        break;
        case 99 :
            menuAdmin(sch,pln,pas);
        break;
        default :
            cout << "Menu tidak tersedia..." << endl;
            getch();
            goto pilihbalik;
        }

    }
}

void menuAdmin(schedules &sch , plane &pln , passenger &pas) {
    int pilih;
    string username,password;
    cout << endl;

        if (!login) {
	    system("CLS");
	    cout << "========================================" << endl;
		cout <<	"=            Zero Reservation          =" << endl;
		cout << "========================================" << endl;
		cout << "     -- Administration Login Page --  \n" << endl;
	    cout << " Username : "; cin >> username;
	    cout << " Password : "; cin >> password;
        }

	    if (loginAdmin(username , password) || login){
	    	login = true;
	        do {
	            pilihbalik:
	             system("CLS");
	             cout << "========================================" << endl;
	            cout <<	"=            Zero Reservation          =" << endl;
	            cout << "========================================" << endl;
	            cout << " 1. Menambah Data Jadwal Penerbangan, Pesawat, dan Passenger" << endl;
	            cout << " 2. Menghapus Data Jadwal Penerbangan, Pesawat, dan Passenger " << endl;
	            cout << " 3. Mengubah Data Jadwal Penerbangan, Pesawat, dan Passenger" << endl;
	            cout << " 4. Relasi Jadwal dengan Pesawat" << endl;
	            cout << " 5. Hapus Relasi Jadwal dengan Pesawat" << endl;
	            cout << " 6. Hapus Relasi Pesawat dengan Passenger" << endl;
	            cout << " 7. Melihat Jadwal " << endl;
	            cout << " 8. Melihat Pesawat" << endl;
	            cout << " 9. Melihat Passenger" << endl;
	            cout << " 10. Melihat Jadwal -- Pesawat" << endl;
	            cout << " 11. Melihat Pesawat -- Pessanger" << endl;
	            cout << " 99. Log Out" << endl;
	            cout << "\nPilih Menu : " ;
	            cin >> pilih;
	    			if(cin.fail())
				        {
				          cin.clear();
				          cin.ignore();
				          cout << "Error, Input tipe datanya salah.";
				        }

	            switch (pilih) {
	                case 1 :
	                    menuTambah(sch,pln,pas);
	                break;
	                case 2 :
	                   menuDelete(sch,pln,pas);
	                break;
	                case 3 :
	                    menuEdit(sch, pln , pas);
	                break;
	                case 4 :
	                    addJadwaltoPlane(sch , pln);
	                break;
	                case 5 :
	                	deleteRelasibyID(sch);
	                break;

	                case 6 :
                        deleteRelasi2byID(pln);
	                break;

	                case 7 :
	                    printInfoSchedules(sch);
	                    getch();
	                break;

	                case 8 :
                        printInfoPlane(pln);
	                    getch();
                    break;

                    case 9 :
	                    printInfoPassenger(pas);
	                    getch();
                    break ;

	                case 10 :
	                	printSch_Pln(sch);
	                	getch();
	                break;
	                case 11 :
	                	printplane_passenger(pln);
	                	getch();
	                break;
	                case 99:
	                    mainMenu(sch , pln , pas);
	                    break;
	                default :
	                    cout << "Menu tidak ada : " << endl;
	                    goto pilihbalik;
	                break;
	            }
	        } while (pilih != 99);
	    } else {
	        cout << "Username atau Password salah" << endl;
	        getch();
	        mainMenu(sch,pln,pas);
	    }

}

void menuPassanger(schedules &sch , plane &pln , passenger &pas) {
    int pilih;
    string username,password,ID;
    addressPassenger p;

    system("CLS");
    cout << "========================================" << endl;
	cout <<	"=            Zero Reservation          =" << endl;
	cout << "========================================" << endl;
	cout << "        -- Passenger Login Page --   \n " << endl;
    cout << " Passenger ID : "; cin >> ID;
    cout << " Username     : "; cin >> username;
    cout << " Password     : "; cin >> password;

    if (loginPassanger(pas , ID ,username , password)) {
        p = findElmPassenger(pas , ID);
        do {
            pilihbalik:
            system("CLS");
            cout << "Welcome - " << p->info.name << endl;
            cout << "========================================" << endl;
        	cout <<	"=            Zero Reservation          =" << endl;
        	cout << "========================================" << endl;
            cout << " 1. Memesan Penerbangan" << endl;
            cout << " 2. Melihat Pemesanan " << endl;
            cout << " 3. Membatalkan Pemesanan " << endl;
            cout << " 4. Melihat Jadwal Penerbangan & Maskapai" << endl;
            cout << " 5. Edit Profile" << endl;
            cout << " 99. Back" << endl;
            cout << "\nPilih Menu : " ;
            cin >> pilih;

            if(cin.fail())
            {
              cin.clear();
              cin.ignore();
              cout << "Error,Input hanya angka... " << endl;
              getch();
              goto pilihbalik;
            } else {

                switch (pilih) {
                case 1 :
                    system("CLS");
                    pesanPenerbangan(pln , p);
                break;
                case 2 :
                    printPesanan(pln , p);
                break;
                case 3 :
                    pembatalan(pln , p);
                break;
                case 4 :
                	printSch_Pln(sch);
                	getch();
                break;
                case 5 :
                	editProfile(pas, p);
                	getch();
                break;


                case 99 :

                break;
                break;
                        default :
                        cout << "Menu tidak ada : " << endl;
                    break;
                }
            }
        } while (pilih != 99);
    } else {
        cout << "Username atau Password salah" << endl;
        getch();
    }
    mainMenu(sch,pln,pas);
}



void mainMenu(schedules &sch, plane &pln , passenger &pas) {
    //clrscr();
    int pilih;
    login = false;
         pilihbalik:
        system("CLS");
        cout << "========================================" << endl;
    	cout <<	"=            Zero Reservation          =" << endl;
    	cout << "========================================" << endl;
    	cout << currentDateTime() << endl;
    	cout << "----------------------------------------" << endl;
    	cout << "              -- Summary -- " << endl;
    	cout << "----------------------------------------" << endl;
    	cout << "Jadwal : " << countSchedules(sch) << " || Pesawat : "
    		 << countPlane(pln) << " || Passenger " << countPassenger(pas) << endl;
    	cout << "----------------------------------------" << endl;
        cout << " 1. Administration " << endl;
        cout << " 2. Passengers " << endl;
        cout << " 99. Exit" << endl;
        cout << "\nPilih Menu : " ;
        cin >> pilih;

        if(cin.fail())
        {
          cin.clear();
          cin.ignore();
          cout << "Error,Input hanya angka... " << endl;
          getch();
          goto pilihbalik;
        } else {

        switch (pilih) {
            case 1 :
                menuAdmin(sch , pln , pas);
            break;
            case 2 :
                menuPassanger(sch , pln , pas);
            case 99 :
                exit(1);
                break;
            default :
                cout << "Tidak ada pilihan" << endl;
                getch();
                goto pilihbalik;
            break;
        }
    }
}

void menuTambah(schedules &sch, plane &pln , passenger &pas){
    int pilih;
    pilihbalik:
    system("CLS");
    cout << "========================================" << endl;
    cout <<	"=            Zero Reservation          =" << endl;
    cout << "========================================" << endl;
    cout << " 1. Menambah Jadwal Penerbangan " << endl;
    cout << " 2. Menambah Data Pesawat " << endl;
    cout << " 3. Menambah Data Passenger" << endl;
    cout << " 99. Exit" << endl;
    cout << "\nPilih Menu" ;
    cin >> pilih;

    if(cin.fail())
        {
          cin.clear();
          cin.ignore();
          cout << "Error, Input hanya angka...";
          goto pilihbalik;
          // menuTambah( sch, pln , pas);
        } else {

            switch (pilih) {
            case 1 :
                system("CLS");
                insertSchedulesMain(sch);
            break;
            case 2 :
                system("CLS");
                insertPlaneMain(pln);
            break;
            case 3 :
                system("CLS");
                insertPassengerMain(pas);
            break;
            case 99 :
                menuAdmin(sch,pln,pas);
            break;
            default :
                cout << "Menu tidak tersedia..." << endl;
                getch();
                goto pilihbalik;
            }

        }
}


/*============================
=            Edit            =
============================*/
void editSchedules(schedules &l){
	addressSchedules p;
	p = l.first;

	string ID;
char pilih ;
	dataSchedules x;

	do {
		cout << "========================================" << endl;
	    cout <<	"=            Zero Reservation          =" << endl;
	    cout << "========================================" << endl;
		cout << "Masukkan ID Schedules : "  ;
		cin >> ID;

		p = findElmSchedules(l,ID);

		if (p == NULL) {
			cout << "Data tidak ditemukan" << endl;
		} else {
			cout << "\t --Edit --" << endl;
			pilihbalik:
			cout << " Masukkan ID Schedules baru : ";
			cin >> x.schID;

			 if ( checkSchedulesID( l ,x.schID) ){
                cout << " -- Already Exist" << endl;
                cout << "Input another name " << endl;
                goto pilihbalik;
             }
			cout << " Masukkan Tanggal baru : ";
			cin >> x.date;
            p->info.schID = x.schID;
            p->info.date = x.date;
		}


		cout << "Edit Data Lagi ? ( Y / N ) ";
		cin >> pilih;
	} while ( pilih != 'n' && pilih != 'N');

}

void editPlane(plane &l) {
	addressPlane p = l.first;

	string ID;
	char pilih ;
	dataPlane x;
		cout << "========================================" << endl;
	    cout <<	"=            Zero Reservation          =" << endl;
	    cout << "========================================" << endl;

	do {
		cout << "Masukkan ID Pesawat : "  ;
		cin >> ID;

		p = findElmPlane(l,ID);

		if (p == NULL) {
			cout << "Data tidak ditemukan" << endl;
		} else {
			cout << "\t --Edit --" << endl;
			pilihbalikID:
			cout << " Masukkan ID Pesawat baru : ";
			cin >> x.planeID;

            if ( checkPlaneID( l ,x.planeID) ){
                cout << " -- Already Exist" << endl;
                cout << "Input another name " << endl;
                goto pilihbalikID;
            }

			cout << " Masukkan Type baru : ";
			cin >> x.type;
			cout << "Masukkan Rute baru : ";
			cin >> x.route;
			pilihbalik:
			cout << "Masukkan Harga baru : ";
			cin >> x.price;
				if(cin.fail()) {
					cin.clear();
					cin.ignore();
					cout << "Bukan tipe data harga, masukkan angka" << endl;
					goto pilihbalik;
				}

			pilihbalik2:
			cout << "Masukkan Kapasitas baru : ";
			cin >> x.capacity;
				if(cin.fail()){
					cin.clear();
					cin.ignore();
					cout << "Bukan tipe data kapasitas, masukkan angka" << endl;
					goto pilihbalik2;
				}

				p->info.planeID = x.planeID;
				p->info.type = x.type;
				p->info.route = x.route;
				p->info.price = x.price;
				p->info.capacity = x.capacity;
		}


		cout << "Edit Data Lagi ? ( Y / N ) ";
		cin >> pilih;
	} while ( pilih != 'n' && pilih != 'N');

}

void editPassenger(passenger &l){
    addressPassenger p = l.first;

	string ID;
	char pilih ;
	dataPassenger x;
	bool ada;

	do {
		cout << "========================================" << endl;
	    cout <<	"=            Zero Reservation          =" << endl;
	    cout << "========================================" << endl;
		cout << "Masukkan ID Passenger : "  ;
		cin >> ID;

		p = findElmPassenger(l,ID);

		if (p == NULL) {
			cout << "Data tidak ditemukan" << endl;
		} else {
			cout << "\t --Edit --" << endl;
			pilihbalikID:
			cout << " Masukkan ID Passenger baru : ";
			cin >> x.passengerID;

            if ( checkPassengerID( l ,x.passengerID) ){
                cout << " -- Already Exist" << endl;
                cout << "Input another name " << endl;
                goto pilihbalikID;
            }

			cout << " Masukkan Nama baru : ";
			cin >> x.name;
			cout << "Masukkan Username baru : ";
			cin >> x.username;
			cout << "Masukkan Password baru : ";
			cin >> x.password;
			pilihbalik:
			cout << "Masukkan Umur baru : " ;
			cin >> x.age;
				if (cin.fail()) {
					cin.clear();
					cin.ignore();
					cout << "Tipe data umur salah, masukkan angka" << endl;
					goto pilihbalik;
				}
			cout << "Masukkan Gender baru : ";
			cin >> x.gender;
			cout << "Masukkan Address baru : ";
			cin >> x.address;

				p->info.passengerID = x.passengerID;
				p->info.name = x.name;
				p->info.username = x.username;
				p->info.password = x.password;
				p->info.age = x.age;
				p->info.gender = x.gender;
				p->info.address = x.address;
		}

		cout << "Edit Data Lagi ? ( Y / N ) ";
		cin >> pilih;
	} while ( pilih != 'n' && pilih != 'N');

}


void editProfile(passenger &l , addressPassenger p) {
		system("CLS");
		cout << endl;
		cout << "========================================" << endl;
	    cout <<	"=            Zero Reservation          =" << endl;
	    cout << "========================================" << endl;
	    char pilih;
	    balikawal:
	    cout << "1. Mengubah Identitas " << endl
	    	<<	"2. Mengubah Password "	<< endl
	    	<< 	"Pilih Menu ..." << endl;

	    cin >> pilih;

	    switch (pilih) {
        case '1' :
                    system("CLS");
                    cout << endl;
                    cout << "========================================" << endl;
                    cout <<	"=            Zero Reservation          =" << endl;
                    cout << "========================================" << endl;
					cout << " Masukkan Nama baru : ";
                    cin >> p->info.name;
                    pilihbalik:
                    cout << "Masukkan Umur baru : " ;
                    cin >> p->info.age;
                        if (cin.fail()) {
                            cin.clear();
                            cin.ignore();
                            cout << "Tipe data umur salah, masukkan angka" << endl;
                            goto pilihbalik;
                        }
                    cout << "Masukkan Gender baru : ";
                    cin >> p->info.gender;
                    cout << "Masukkan Address baru : ";
                    cin >> p->info.address;

                    cout << "\n --- Profile already update .... ---";
                    break;
        case '2' :
                     system("CLS");
                    cout << endl;
                    cout << "========================================" << endl;
                    cout <<	"=            Zero Reservation          =" << endl;
                    cout << "========================================" << endl;
             		cout << "Masukkan Username Lama : " << endl;
                    string username;
                    cin >> username;
                    cout << "Masukkan Password Lama : " << endl;
                    string password;
                    cin >> password;
                    bool cocok;

                    if (password == p->info.password && username == p->info.username){
                        cout << " > Masukkan username baru : ";
                        cin >> p->info.username;
                        cout << " > Masukkan password baru : ";
                        cin >> p->info.password;
                        cocok = true;
                    } else
                        cocok = false;

                    if (cocok)
                        cout << " -- Success... Username & Password are update... --" << endl;
                    else {
                        cout << " -- Failed... Incorrect username or password... --" << endl;
                       	goto balikawal;
        			}
        break;
        }
}





/*=====  End of Edit  ======*/



/*=====================================
=            Check Element            =
=====================================*/

bool checkPlaneID(plane l , string ID) {

	addressPlane p = l.first;

	p = findElmPlane(l , ID);

	if ( p == NULL) {
		return false;
	} else {
		return true;
	}

}

bool checkSchedulesID(schedules l , string ID) {
	addressSchedules p = l.first;

	p = findElmSchedules(l , ID);

	if ( p == NULL)
		return false;
	else
		return true;

}

bool checkPassengerID(passenger l , string ID) {
	addressPassenger p = l.first;

	p = findElmPassenger(l , ID);

	if ( p == NULL)
		return false;
	else
		return true;
}

bool checkRelasi2(listRelasi2 l , string ID){
	addressRelasi2 q;

	q = findElmRelasi2( l , ID);

	if ( q == NULL)
        return false;
	else
        return true;
}

bool checkRelasi(listRelasi l , string ID){
	addressRelasi q;

	q = findElmRelasi( l , ID);

	if ( q == NULL)
        return false;
	else
		return true;
}



/*=====  End of Check Element  ======*/


/*----------  Date  ----------*/
const string currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);

    strftime(buf, sizeof(buf), "Date : %d-%m-%Y - Local Time : %X", &tstruct);

    return buf;
}


void pembatalan(plane &l , addressPassenger q) {

    string id;
    system("CLS");
	cout << endl;
	cout << "========================================" << endl;
	cout <<	"=            Zero Reservation          =" << endl;
	cout << "========================================" << endl;
    cout << "Masukkan ID Pesawat yang ingin dibatalkan : "; cin >> id;

    addressPlane p = findElmPlane( l , id);

    if (p == NULL) {
        cout << " -- Pesawat tidak ditemukan --" << endl;
    } else {
        addressRelasi2 r = p->child.first;

            if (r->info->info.passengerID == q->info.passengerID ) {
                cout << p->info.planeID;
                p->info.capacity++;
                if (r->next == NULL) {
                    p->child.first= NULL;

                } else {
                    if (r == p->child.first && r->next != NULL ){
                        deleteFirstR2(p->child);
                    } else if (next(r) == NULL) {
                        deleteLastR2(p->child);
                    }
                    else {
                        addressRelasi2 q = p->child.first;

                        while (q->next != r) {
                            q = q->next;
                        }
                        q->next = r->next;
                        r->next = NULL;
                        delete r;
                    }
                }
                cout << " Berhasil dibatalkan..." << endl;
        } else {
            cout << "-- Failed...," << p->info.planeID << " not match to any order " << endl;
        }
    }
    getch();
}


int countSchedules(schedules l){
	addressSchedules p;
	int i = 0;
	p = l.first;

	while (p!= NULL) {
		i++;
		p = p->next;
	}

	return i;
}

int countPlane(plane l) {
	addressPlane p;
	int i = 0;
	p = l.first;

	while (p!= NULL) {
		i++;
		p = p->next;
	}

	return i;
}

int countPassenger(passenger l) {
	addressPassenger p;
		int i = 0;
	p = l.first;

	while (p!= NULL) {
		i++;
		p = p->next;
	}

	return i;
}
