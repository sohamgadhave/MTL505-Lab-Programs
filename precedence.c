#include<stdio.h>
int a = 1, b = 2, c = 3;
int f(void);

int main(){
    printf("a = %d\tb = %d\tc = %d\n",a, b, c);
    printf("%d\n",f());
    printf("a = %d\tb = %d\tc = %d\n",a, b, c);
    return 0;
}
int f(void) {
    int b, c;
    a = b = c = 4;
    return (a + b + c);
}
