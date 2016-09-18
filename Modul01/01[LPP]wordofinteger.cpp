#include <cstdio>
#include <cmath>

void bilSatuan( int x ) {
	if ( x == 1 ) {
		printf("Satu ");
	}else if ( x == 2) {
		printf("Dua ");
	}else if ( x == 3) {
		printf("Tiga ");
	}else if ( x == 4) {
		printf("Empat ");
	}else if ( x == 5) {
		printf("Lima ");
	}else if ( x == 6) {
		printf("Enam ");
	}else if ( x == 7) {
		printf("Tujuh ");
	}else if ( x == 8) {
		printf("Delapan ");
	}else if ( x == 9) {
		printf("Sembilan ");
	}else if ( x == 10) {
		printf("Sepuluh ");
	}else if ( x == 11) {
		printf("Sebelas ");
	}
}

void bilTerbilang( int y ) {
	if ( y <= 11) {
		bilSatuan(y);
	} else if ( y > 11 && y <= 19 ){
		bilTerbilang( y % 10);
		printf("Belas ");
	} else if ( y >= 20 && y <= 99){
		bilTerbilang( y / 10);
		printf("Puluh ");
		bilTerbilang( y % 10);
	} else if ( y >= 100 && y <= 199){
		printf("Seratus " );
		bilTerbilang( y % 100);
	} else if ( y >= 200 && y <= 999) {
		bilTerbilang(y/100);
		printf("Ratus ");
		bilTerbilang(y % 100);
	} 
}  

int main() {
	int bilangan;
	scanf("%d" , &bilangan);
	if (bilangan >= 0 && bilangan <= 999) {
		if (bilangan == 0)  
			printf("nol ");
		else {
		bilTerbilang(bilangan);
		printf("\n");
		}
	} else 
		printf("Error : Data over flow\n");
	return 0 ;
} 
