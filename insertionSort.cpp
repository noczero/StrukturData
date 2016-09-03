#include <iostream>

using namespace std;

int main()
{
    int A[6];
    int i,j,tmp;

    //input
    for ( i = 1 ; i <= 5 ; i++) {
        cin >> A[i];
    }

    //insertionSort;
    for (i = 2 ; i <= 5; i++) {
        tmp = A[i];
        j = i;

        while ((j>1 ) && (tmp < A[j-1])) {
            A[j] = A[j-1];
            j--;
        }
        A[j] = tmp;
    }

    //cetak
    for (i= 1; i <= 5; i++ ) {
        cout << A[i] << "," ;
    }

    return 0;
}
