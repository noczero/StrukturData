/*
Faktorisasi Prima
Time limit: 1 s
 
Memory limit: 64 MB
 
Deskripsi
 
Diberikan sebuah bilangan bulat positif N. Tentukanlah faktorisasi primanya, dalam bentuk p1^a1 x p2^a2 x ... x pK^aK, dengan p adalah bilangan prima dan a adalah pangkatnya. Apabila pangkatnya adalah 1, maka tidak perlu dituliskan beserta tanda pangkatnya. Bilangan-bilangan prima harus terurut dari kecil ke besar.
 
Sebagai contoh, faktorisasi prima dari 56 adalah 2^3 x 7, sedangkan faktorisasi prima dari 75 adalah 3 x 5^2.
 
Format Masukan
 
Sebuah baris berisi sebuah bilangan bulat N.
 
Format Keluaran
 
Sebuah baris berisi faktorisasi prima dari N dengan format sesuai deskripsi.
 
Contoh Masukan
 
693
Contoh Keluaran
 
3^2 x 7 x 11
Batasan
 
2 ≤ N ≤ 1.000.000

*/

#include <iostream>
#include <math.h>

using namespace std;

int main() {
	int n,i,p,jum,m;

	cin >> n;

	i = 2;
	jum	= 1;
	m = n;

	while (jum< n - 1) {
		p = 0;

		while (m%i == 0) {
			p ++;
			m = m / i;
		}

		if (p>0){
			jum *= pow(i,p);

			if (p > 1) cout << i << "^" <<p;

			else cout << i;

			if (jum < n - 1) cout << " x ";
		}
		i++;
	}
	if (n==1 || n==2) cout << n << endl;
	else
		cout << endl;

	return 0;
}