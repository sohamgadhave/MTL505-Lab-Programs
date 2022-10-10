#include <stdio.h>

void reverse(int *, int n);

void main(){
    int n, i = 0;
    printf("Enter the size of the arrays:\n");
    scanf("%d", &n);
    int a[n];
    printf("Enter the array:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int *p = a;
    reverse(p, n);
    for(i = 0; i < n; i++)
        printf("%d\t", a[i]);
}

void reverse(int *p, int n) {
    int *q = p + (n-1), i = 0, temp;
    while(p < q) {
        temp = *p;
        *p = *q;
        *q = temp;
        p--;
        q++;
    }
}
