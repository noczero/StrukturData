#include <cstdio>
#include "clock.h"

using namespace std;

bool isValid( int HH , int MM , int SS) {
    if ((HH >= 0 && HH <= 23) && (MM>=0 && MM <=59) && (SS >= 0 && SS <=59))
        return true;
    else
        return false;
}

clock makeClock( int HH, int MM , int SS){
    clock c;

    c.HH = HH;
    c.MM = MM;
    c.SS = SS;
    return c;
}

int getHour(clock c) {
    int HH = c.HH;
    return HH;
}
int getMinute(clock c) {
    int MM = c.MM;
    return MM;
}

int getSecond(clock c){
    int SS = c.SS;
    return SS;
}

void setHour(clock &c , int newHH){
    c.HH = newHH;
}

void setMinute(clock &c , int newMM){
    c.MM = newMM;
}
void setSecond(clock &c , int newSS) {
    c.SS = newSS;
}

bool isEqual(clock c1, clock c2) {
    if ((c1.HH == c2.HH) && (c1.MM == c2.MM) & (c1.SS == c2.SS))
        return 1;
    else
        return 0;
}

clock addClock(clock c1, clock c2){
    long int totalDetik, sisaMenit, sisaJam;
    clock c;

    totalDetik = (c1.HH * 3600 + c2.HH *3600 + c1.MM * 60 + c2.MM * 60 + c1.SS + c2.SS);

    c.HH = totalDetik / 3600;
    sisaJam = totalDetik % 3600;
    c.MM = sisaJam / 60;
    c.SS = sisaJam % 60;

    if (c.HH > 24) {
        c.HH = c.HH - 24;
    }

    return c;
}

void printClock(clock c) {
    printf("%d : %d : %d \n", c.HH , c.MM , c.SS);
}

