#include<stdio.h>

void main() {
    int a = 5, x, y;
    x = a++;
    y = ++a;
    printf("x and y are %d and %d", x, y);
}
