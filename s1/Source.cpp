#include <stdio.h>

void interschimba(short int a, short int b) {
	short int aux;
	aux = a;
	a = b;
	b = aux;
}

void interschimba2(short int* pa, short int* pb) {
	short int aux;
	aux = *pa;
	*pa = *pb;
	*pb = aux;
}

void interschimba3(short int& ra, short int& rb) {
	short int aux;
	aux = ra;
	ra = rb;
	rb = aux;
}

int main() {
	int x = 22; 
	int* y;
	y = &x;

	printf("y= %d", *y);

	x = 123;
	printf("y= %d", *y);

/*	short int x = 10;
	short int y = 7;

	printf("x = %d, y = %d", x, y);
	interschimba(x, y);
	printf("x = %d, y = %d", x, y);

	printf("x = %d, y = %d", x, y);
	interschimba2(&x, &y);
	printf("x = %d, y = %d", x, y);


	printf("x = %d, y = %d", x, y);
	interschimba3(x, y);
	printf("x = %d, y = %d", x, y);
	*/
}