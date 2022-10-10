#include <stdio.h>

int compare(int *, int *, int);

void main() {
    int n;
    printf("Enter the size of the arrays:\n");
    scanf("%d", &n);
    int a[n], b[n], i = 0;
    printf("Enter the first array:\n");
    for(i = 0; i< n; i++)
        scanf("%d", &a[i]);
    printf("Enter the second array:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &b[i]);
    int *p = a, *q = b;
    if(compare(p, q, n) == 1)
        printf("The two arrays are identical:");
    else
        printf("The two arrays are not identical");
}

int compare(int *p, int *q, int n) {
    int i = 0;
    for(i = 0; i < n; i++)
        if(*(p + i) != *(q + i))
            return 0;
    return 1;
}
