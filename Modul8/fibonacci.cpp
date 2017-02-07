#include <iostream>

using namespace std;

int fibonacci(int n) {
	
	if (n == 1) {
		return 1;
	} if (n == 2) {
		return 1;
	} else {
		return fibonacci(n-1) + fibonacci(n-2);

	}

}

int main() {
	int n, result;
	cout << "Masukkan input : " ; 
	cin >> n;
 
	result = fibonacci(n);
	cout << result;

	return 0;
}