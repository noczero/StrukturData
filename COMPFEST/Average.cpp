#include <cstdio>
#include <iostream>

using namespace std;

int main() {
	const int all = 12;
	double 
		data[12] = {0},
		average,
		sum = 0.0 ;

	for (int i = 0 ; i < all ; i++) {
		cin >> data[i];
		sum += data[i];
	}

	average = sum / all;
	printf("Rp %2f \n", average );

	return 0;
}

/*
Result
Sample Input 	Sample Output
100.00 			$1581.42
489.12
12454.12
1234.10
823.05
109.20
5.27
1542.25
839.18
83.99
1295.01
1.75

*/