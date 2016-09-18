#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	int i , j , n , count , a[20];

	cin >> a[0];

	while (a[0] != -1) {
		n = 1;
		for ( ; ; n++) {
			cin >> a[n];
			
			if (a[n] == 0) 
				break;  
		}

		count = 0;

		for (i = 0 ; i < n - 1; i++) {
			for (j = i + 1; j < n ; j++) {
				if (a[i]*2 == a[j] || a[j] * 2 == a[i])
					count++;
			}
		}
		printf("%d\n", count );
		cin >> a[0];
	}
	return 0;
}

/* result
Sample Input 		Sample Output
1 4 3 2 9 7 18 22 0 3
2 4 8 10 0 			2
7 5 11 13 1 3 0 	0
–1
*/