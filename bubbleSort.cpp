#include <iostream>

using namespace std;

int main() {
    //kamus
    //int A[] = {3 , 2 , 6 , 4 , 8};

    int A[5];
    int i,j, tmp ;
    //inpur
    for (i = 1 ; i <= 5 ; i++ ) {
        cin >> A[i] ;
    }
    for (i = 5 ; i >= 0 ; i--) {
        for (j = 2 ; j <= i ; j++) {
            if (A[j-1] > A[j]) {
                tmp = A[j-1];
                A[j-1] = A[j];
                A[j] = tmp;
            }
        }
    }
    //printArray
    for (i = 1 ; i <= 5 ; i++ ){
        cout << A[i] << "," ;
    }

return 0;
}
