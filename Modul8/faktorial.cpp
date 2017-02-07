#include <iostream>
#include <cstdio>

using namespace std;

int Factorial(int n){
	cout << "I am calculating( " << n << ")\n";
	int F;
	if (n == 0) {
		return 1;
	} 
	else {
	F = n * Factorial(n-1);
	cout << "Done ! F(" << n << ") = " << F << "\n";
	return F;
	}
}


int main() {
	int n;
	cout << "Give me an n : ";
	cin >> n ; 

	int result = Factorial(n);

	cout << result;
	return 0;

}