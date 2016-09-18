#include <cstdio>
#include "clock.cpp"
#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
    int jam[1];
    int menit[1];
    int detik[1];
    int pilih, JamBaru, MenitBaru, DetikBaru;
    clock waktu, waktu2, waktuBaru;


    for (int i = 0; i <= 1; i++)
    {
      /* code */
      printf("Masukan Waktu Jam %d (12 34 56) \n", i+1);
      cin >> jam[i];
      cin >> menit[i];
      cin >> detik[i];
    }

    waktu = makeClock(jam[0], menit[0], detik[0]);
    waktu2 = makeClock(jam[1], menit[1], detik[1]);
    do {
        if (isValid(jam[0], menit[0], detik[0]) && isValid(jam[1], menit[1], detik[1])){
            printf("1. Get Hour \n");
            printf("2. Get Minute \n");
            printf("3. Get Second \n");
            printf("4. Set Hour \n");
            printf("5. Set Minute \n");
            printf("6. Set Second \n");
            printf("7. Check Equal \n");
            printf("8. Add Clock \n");
            printf("9. Print Clock \n");
            printf("10. Exit \n");
            cin >> pilih;
            switch (pilih) {
                case 1 :
                    printf("%d jam di waktu pertama \n ",  getHour(waktu));
                    printf("%d jam di waktu kedua \n",  getHour(waktu2));
                break;
                case 2 :
                    printf("%d menit waktu pertama \n" , getMinute(waktu));
                    printf("%d menit waktu kedua \n" , getMinute(waktu2));
                break;
                case 3 :
                    printf("%d detik waktu pertama \n" , getSecond(waktu));
                    printf("%d detik waktu kedua \n", getSecond(waktu2));
                break;
                case 4 :
                    printf("Set Jam Waktu Pertama : \n");
                    cin >> JamBaru;
                    setHour(waktu,JamBaru);

                    printf("Set Jam Waktu Kedua: \n");
                    cin >> JamBaru;
                    setHour(waktu2,JamBaru);
                break;
                case 5 :
                    printf("Set Menit Waktu Pertama: \n");
                    cin >> MenitBaru;
                    setMinute(waktu,MenitBaru);
                  
                    printf("Set Menit Waktu Kedua: \n");
                    cin >> MenitBaru;
                    setMinute(waktu2,MenitBaru);
                  
                break;
                case 6 :
                    printf("Set Detik Waktu Pertama : \n");
                    cin >> DetikBaru;
                    setSecond(waktu,DetikBaru);

                    printf("Set Detik Waktu Kedua : \n");
                    cin >> DetikBaru;
                    setSecond(waktu2,DetikBaru);
                break;

                case 7 :
                    if (isEqual(waktu, waktu2))
                        printf("Waktunya sama \n");
                    else
                        printf("Waktu tidak sama\n");
                break;

                case 8 :
                    waktuBaru = addClock(waktu, waktu2);
                    printf("Waktu baru : %d : %d : %d \n", waktuBaru.HH, waktuBaru.MM, waktuBaru.SS);
                break;

                case 9 :
                    printf("Waktu Pertama \t");
                    printClock(waktu);
                    printf("Waktu Kedua \t");
                    printClock(waktu2);
                    printf("Waktu Baru \t");
                    printClock(waktuBaru);
                break;

                case 10 :
                    break;
            default :
                printf("Pilihan Salah \n");
            }
        }
        else {
            printf("Waktu tidak valid");
            break;
        }
    } while (pilih != 10);
  
    return 0 ;
}
