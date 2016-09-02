#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int L, R, J, X, T, P, K;
/* L = Bensin
R = Harga Bensin 1 Liter
J = Jarak
P = Total yg harus dibayar = L * R * J
X = bayaran 
K = kembalian = X - P 
*/
string S;

int main() {

	scanf("%d", &T);
	while (T--) {
		scanf("%d %d %d %d", &L, &R, &J, &X);
		cin >> S;

		if (S == "kabur") {
			P = L * R * J;
			K = -P; // kabur = rugi
			printf("%d", K);
		} 
		else {
			P = L * R * J;
			K = X - P;
			printf("%d", K );
		}
	}
	return 0 ;
}

/* Result

Masukan
3
4 2 4 100 bayar
2 2 3 50 kabur
6 4 3 72 bayar

Keluaran
68
-12
0

*/