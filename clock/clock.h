#ifndef CLOCK_H_INCLUDED
#define CLOCK_H_INCLUDED

typedef struct{
    int HH,MM,SS;
}clock;

bool isValid( int HH , int MM , int SS);
clock makeClock( int HH, int MM , int SS);

int getHour(clock c);
int getMinute(clock c);
int getSecond(clock c);

void setHour(clock &c , int newHH);
void setMinute(clock &c, int newMM);
void setSecond(clock &c, int newSS);

bool isEqual(clock c1, clock c2);
clock addClock(clock c1, clock c2);
void printClock(clock c);
#endif // CLOCK_H_INCLUDED
