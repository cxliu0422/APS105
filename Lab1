//part1
# include <stdio.h>
int main (void){
  printf ("C uses escape sequences for a variety of purposes.\n");
  printf ("Some common ones are:\n");
  printf ("to print \", use \\\"\n");
  printf ("to print \\, use \\\\");
  printf ("\nto jump to a new line, use \\n");
  return 0;
}

//part2
# include <stdio.h>
int main (void){
    printf("Enter the daily rate: ");
    double inputRate;
    scanf("%lf", &inputRate);
    printf("Enter the rental period (in days): " );
    double inputPeriod;
    scanf("%lf", &inputPeriod);
    int freeDays;
    freeDays = inputPeriod/4;
    const double tax = 1.13;
    double charge;
    charge = tax*(inputRate*(inputPeriod-freeDays));
    printf("\nYour total free day(s) in this rental is: %d",freeDays);
    printf("\nYour total charge including taxes is: %.2lf",charge);
    return 0;
}

//part3
# include <stdio.h>
int main (void){
    printf("Please provide a distance in metres: ");
    double inputMeters;
    scanf("%lf", &inputMeters);
    const double memtertoyard = 1.0936133;
    const double memtertofeet = 3.2808399;
    const double memtertoinches = 39.3700787;
    int outputyard;
    outputyard = inputMeters * memtertoyard;
    int outputfeet;
    outputfeet = (inputMeters - (outputyard/memtertoyard))* memtertofeet;
    int outputinches;
    outputinches = (inputMeters - (outputyard/memtertoyard)-outputfeet/memtertofeet)* memtertoinches;
    double remainder;
    remainder = (inputMeters - (outputyard/memtertoyard)-outputfeet/memtertofeet-outputinches/memtertoinches)* memtertoinches;
    printf("%d yards, ",outputyard);
    printf("%d feet, ",outputfeet);
    printf("%d inches, ",outputinches);
    printf("%.2lf inches remainder",remainder);
    return 0;
}
