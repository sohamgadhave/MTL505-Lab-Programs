#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define SIZE 20

char* to_lower(char *string) {
    char lower_string[SIZE];
    int i = 0;
    for(i = 0; i < strlen(string); i++)
        lower_string[i] = tolower(string[i]);
    lower_string[i] = '\0';
    return lower_string;
}

void main() {
    char country[][SIZE] = {"canada", "england", "france", "italy"};
    char capital[][SIZE] = {"ottawa", "london", "paris", "rome"};
    int response_size = 20, i = 0;
    char response[response_size];

    while(1) {
        printf("\nEnter country or capital: \n");
        gets(response);

        if(strcmp(to_lower(response), "end") == 0)
            break;

        for(i = 0; i < SIZE; i++) {
            if(strcmp(to_lower(response), country[i]) == 0) {
                printf("Capital of %s is %s", country[i], capital[i]);
                break;
            }
            if(strcmp(to_lower(response), capital[i]) == 0) {
                printf("%s is the capital of %s", capital[i], country[i]);
                break;
            }

        }
    }
}
