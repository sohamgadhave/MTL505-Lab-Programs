#include <stdio.h>
#include <string.h>
#define MONTHS 12

int getMonth(char []);
char months[][MONTHS] = {
  "january",
  "february",
  "march",
  "april",
  "may",
  "june",
  "july",
  "august",
  "september",
  "october",
  "november",
  "december"
};

void main() {
  int number_of_students, birthday_frequency[MONTHS] = {0};
  char month[10];

  printf("Enter the number of students: \n");
  scanf("%d", &number_of_students);
  char flush;
  scanf("%c", &flush);

  for(int i = 0; i < number_of_students; i++) {
    printf("Enter the birthday month: ");
    gets(month);
    int month_number = getMonth(month);
    if(month_number == -1) {
      printf("Enter the birthday month properly with all letters as lower case.\n");
      i--;
      continue;
    }
    birthday_frequency[month_number]++;
  }

  //Finding Max of the array
  int max = birthday_frequency[0];
  for(int i = 1; i < MONTHS; i++)
    if(max < birthday_frequency[i])
      max = birthday_frequency[i];

  printf("Maximum birthdays are in the month or month(s): \n");
  
  for(int i = 0; i < MONTHS; i++)
    if(birthday_frequency[i] == max)
      printf("%s\n", months[i]);
}

int getMonth(char month[]) {
  for(int i = 0; i < MONTHS; i++)
    if(strcmp(months[i], month) == 0)
      return i;
  return -1;
}