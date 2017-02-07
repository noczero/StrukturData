#include <iostream>

using namespace std;

int total ( int n) {
	if (n == 1) {
		return 1;
	} else {

		return n + total(n-1);
	}

}

int main() {
	int n, result;
	cout << "Masukkan n : ";
	cin >> n;

	result = total(n);
	cin >> result;
	return 0;

}