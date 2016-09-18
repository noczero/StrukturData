#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int L, R, J, X, T, P, K;
string S;

int main() {

	scanf("%d", &T);
	while (T--) {
		scanf("%d %d %d %d", &L, &R, &J, &X);
		cin >> S;

		if (S == "kabur") {
			printf("-1");
		} 
		else {
			P = L * R * J;
			K = X - P;
			printf("%d", K );
		}
	}
}