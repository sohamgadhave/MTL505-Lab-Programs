#include<stdio.h>


void main() {
    char line[] = "This is a line", search_char;
    printf("Enter the character to be searched: \n");
    scanf("%c", &search_char);

    int i = 0, count = 0;
    while(line[i] != '\0') {
        if(line[i] == search_char)
            count++;
        i++;
    }

    printf("The number of occurences of %c is/are %d", search_char, count);
}
