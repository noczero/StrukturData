#include <cstdio>
#include <math.h>

#define phi 3.14159265

int numTest;
float x , y;

int i;

double calc;
int years;

int main() {
	scanf ("%d", &numTest);

	for (i = 1; i <= numTest ; i++) {
		scanf ("%f %f", &x , &y);

		calc = (x*x + y*y) * phi / 2 / 50; //Area of semicircle

		years = ceil(calc);
		printf("Property %d : this Property will begin eroding in years %d \n", i , years );
	}
printf("End of Output\n");
return 0;
}
