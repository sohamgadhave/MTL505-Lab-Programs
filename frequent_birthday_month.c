#include<stdio.h>
#define MONTHS 12

void main() {
  int number_of_students = 10, birthday_frequency[MONTHS], month = 0;

  //Initializing the array to all 0's
  for(int i = 0; i < MONTHS; i++)
    birthday_frequency[i] = 0;

  for(int i = 0; i < number_of_students; i++) {
    printf("Enter the number of birthday month: ");
    scanf("%d", &month);
    birthday_frequency[month - 1]++;
  }

  //Finding Max of the array
  int max = birthday_frequency[0], max_month = 0;
  for(int i = 1; i < MONTHS; i++)
    if(max < birthday_frequency[i]) {
      max = birthday_frequency[i];
      max_month = i + 1;
    }
  printf("Maximum birthdays are in the month: %d\n", max_month);
}