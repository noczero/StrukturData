#include "queue.h"

void createQueue(Queue &Q){
    int n = sizeof(Q.info) / sizeof(Q.info[0]);
    for (int i = 0; i <= n; i++) {
        Q.info[i] = 0;
    }
        Q.head = -1;
        Q.tail = -1;
}
bool isEmpty(Queue Q) {
    if (Q.head == -1 && Q.tail == -1) {
        return 1;
    } else {
        return 0;
    }
}

bool isFull(Queue Q){
    if (Q.tail == sizeof(Q.info)){
        return 1;
    } else {
        return 0;
    }
}

void enqueue(Queue &Q , infotype x){
    if (isFull(Q)){
        cout << "Queue sudah penuh!" << endl;
    }
    else if (isEmpty(Q)) {
        Q.head = 0;
        Q.tail = 0;
    } else {
        Q.tail++;
    }
    Q.info[Q.tail] = x;
}

infotype dequeue(Queue &Q){
    int x = Q.head;
    if(isEmpty(Q)){
        cout << "Queue sudah kosong!" << endl;
    } else if (Q.head == 0 && Q.tail == 0) {
        Q.head--;
        Q.tail--;
    } else {
        for (int i = 0 ; i <= Q.tail ; i++) {
            Q.info[i] = Q.info[i+1];
        }
        Q.tail--;
    }
    return x;
}

void printInfo(Queue Q) {
    if (isEmpty(Q)) {
        cout << Q.head << " - " << Q.tail << "\t | Empty Queue "  << endl;
    } else {
        cout << Q.head << " - " << Q.tail << "\t | " ;
        for (int i = 0 ; i <= Q.tail ; i++ ) {
            cout << Q.info[i] << " ";
        }
        cout << endl;
    }
}
