#include "square.h"

void main() {
	double num;
	printf("Enter a number\n");
	scanf("%lf", &num);
	printf("The square of %f is %f", num, square(num));
}

