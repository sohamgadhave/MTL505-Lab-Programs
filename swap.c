#include<stdio.h>

void exchange();

int x, y;

void main() {
    printf("Enter the values of x and y\n");
    scanf("%d%d",&x, &y);

    printf("x and y are %d and %d\n", x, y);
    exchange();
    printf("x and y after swapping are %d and %d\n", x, y);
}

void exchange() {
    int z = x;
    x = y;
    y = z;
}
