#include <cstdio>

void ganjil(int x) {
		for ( int i = 1 ; i <= x ; i++) {
			int k = i - 1;
			for ( int j = 1 ; j <= k ; j++) {
				printf(" ");
			}		

			k = (1 * x + 1) - (2 * i - 1);

			for (int j = 1 ; j <= k ; j++) {
				printf("*");
			}
			printf("\n");
		}
}

void genap ( int x ) {
		int y = x/2;
		int z = y;
		int s;
		for ( int i = 1 ; i <= y ; i++) {
			 int kosong = s;

			for (int j = 1; j <= z; j++) {
				printf("*");
			}

			while (kosong >= 0) {
				printf(" ");
				kosong--;
			}

			for (int k = 1; k <= z ; k++){
				printf("*");
			}
			z--;
			s += 2;
			printf("\n");
		}
} 

int main() {
	int i , j , k , jumlah;
	scanf("%d" , &jumlah);

	if (jumlah % 2 == 1) { 
		ganjil(jumlah);
	} else if (jumlah % 2 == 0) {
		genap(jumlah);
	}

	return 0;
}