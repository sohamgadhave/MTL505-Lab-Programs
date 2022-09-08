#include<stdio.h>
#define POUNDS_TO_KG_FACTOR 0.453592
#define OUNCES_TO_KG_FACTOR 0.0283495

void main(){
    float pounds = 0, ounces = 0, pkilograms = 0, okilograms = 0;
    printf("Enter weight in pounds and ounces\n");
    scanf("%f%f", &pounds, &ounces);
    pkilograms = pounds * POUNDS_TO_KG_FACTOR;
    okilograms = ounces * OUNCES_TO_KG_FACTOR;
    printf("%f pounds are %f kgs and %f grams and %f ounces are %f kgs and %f grams", pounds, pkilograms, pkilograms*1000, ounces, okilograms, okilograms*1000);
}
