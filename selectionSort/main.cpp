#include <iostream>

using namespace std;

int main()
{
    int A[6];
    int i,j,tmp, minim;

    //input
    for ( i = 1 ; i <= 5 ; i++) {
        cin >> A[i];
    }

    //selectionSort;
    for(i = 1 ; i <= 4 ; i++) {
        minim = i;
        for(j=i+1 ; j <= 5 ; j++) {
            if (A[j] < A[minim]) {
                minim = j;
            }
        }
        tmp = A[minim];
        A[minim] = A[i];
        A[i] = tmp;
    }

    //cetak
    for (i= 1; i <= 5; i++ ) {
        cout << A[i] << "," ;
    }

    return 0;
}
