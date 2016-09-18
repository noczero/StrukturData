#include <iostream>

using namespace std;

int main(){
	int data[15];
	int x = 30;


	for ( int i = 0 ; i < 15 ; i++){
		data[i] = x;
		x -= 2;
	}

	int *p1 , *p2 , *p3;

	p1 = &data[3];
	p2 = &data[4];

	cout << data[3] << " " << data[7] << endl;
	cout << &data[3] << " " << &data[7] << endl;
	cout << *p1 << " " << *p2 << endl;
	cout << &p1 << " " << &p2 << endl;
	cout << p1 << " " << p2 << endl;

	p3 = p1;
	cout << &p1 << " " << &p2 << " " << &p3 << endl;
	cout << p1 << " " << p2 << " " << p3 << endl;
	cout << *p1 << " " << *p2 << " " << *p3 << endl;

	*p3 = *p2;
	cout << p1 << " " << p2 << " " << p3 << endl;
	cout << *p1 << " " << *p2 << " " << *p3 << endl;

	p3 = p2;
	*p3 = 60;
	p1 = &data[9];
	p2 += 1;
	cout << p1 << " " << p2 << " " << p3 << endl;
	cout << *p1 << " " << *p2 << " " << *p3 << endl;


	return 0;\
}
