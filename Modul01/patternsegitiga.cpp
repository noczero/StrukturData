#include <iostream>

using namespace std;

int main(){
	int bil,i,j,k,space;
	cin >> bil;

	for (i = bil ; i >= 1 ; --i) {
		for (space = 0; space < bil - i ; ++space) {
			cout << " ";
		}

		for (j = i ; j <= 2*i - 1; ++j) {
			cout << "*";
		}

		for (j = 0 ; j < i - 1; ++j) {
			cout << j;
		}
		cout << endl;
	}
	return 0;
}