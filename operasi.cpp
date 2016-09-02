#include <iostream>

using namespace std;

int main ()
{
	//Variable Declaration
	//
	int a, b;
	int penjumlahan,pengurangan,perkalian;
	double pembagian;
	a = 5;
	b = 2;

	a = a + 1;

	penjumlahan = a + b;
	pengurangan = a - b;
	perkalian = a * b;
	pembagian = a / b;

	// print out the penjumlahan
	cout << "Hasil Pertambahan adalah : " ; 
	cout << penjumlahan <<endl;

	cout << "Hasil Pengurangan adalah : " ;
	cout << pengurangan <<endl;

	cout << "Hasil Perkalian adalah : " ;
	cout << perkalian << endl;

	cout << "Hasil Pembagian adalah : " ;
	cout << pembagian << endl;

	// terimnate program
	return 0;
}