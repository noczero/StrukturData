#include <iostream>

using namespace std;

int main(){
	int a, b = 3;

	a = b;
	a += 2 ; // same with a = a + 2, where a is 3;
	cout << a << endl;


	int c,d ;
	c = 3;
	d = ++c; // ++ cc prints 4,4 .. c ++ print c = 3 , d = 4;
	cout << d << endl;
	cout << c << endl;
	return 0 ;

}