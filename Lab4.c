// APS105S-W22 Lab 4 Part 1

// This program includes a function named "triangle" that outputs Pascal's
// triangle. In general the Pascal's triangle can be represented as:

//             0C0
//           1C1 1C0
//         2C2 2C1 2C0
//       3C3 3C2 3C1 3C0
//      4C4 4C3 4C2 4C1 4C0

// where nCr represents how many ways there are to choose r from n, not
// counting duplicates.

// The formula used to calculate nCr can be written as:
//  nCr=n!/(r!(n-r)!)
// where n! is the factorial of n.

#include<stdio.h>

int factorial (int n){
  int value=1;
  for (int i =1; i<=n; i++){
    value=value*i;
  }
  return value;
}

int choose(int n, int r){
  int answer;
  answer= factorial(r)/(factorial(n)*factorial(r-n));
  return answer;
}

void triangle(int r){
  int row;
  int column;
  for(row=0;row<r;row++){
    for(column=1;column<=(3*r-3*row-3); column++){
      printf(" ");
    }
    for(int n=0; n<=row;n++){
      printf("%-6d",choose(n,row));
    }
    printf("\n");
  }
}

int main(void) {
  int rows;

  do {
    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    if (rows >= 0) {
      triangle(rows);
    }
  } while (rows >= 0);

  return 0;
}


//part2
# include <stdio.h>
# include <math.h>
# include <stdbool.h>
int gcd (int a, int b){
    while (b) {
        int temp = b;
        b=a%b;
        a=temp;
    }
    return a;
}
int main(void){
    
    int startK;
    int stopK;
    int startA;
    int stopA;
    do{
        printf("Enter the number to start searching for k (>2, inclusive): ");
        scanf("%d",&startK);
    }
        while(startK>2);
    do{
        printf("Enter the number to stop searching for k (inclusive)");
        scanf("%d",&stopK);
    }
        while(stopK>startK);
    do{
        printf("Enter the number o start searching for a (>0,inclusive) ");
        scanf("%d",&startA);
    }
        while(startA>0);
    do{
        printf("Enter the number to stop searching for a (inclusive): ");
        scanf("%d",&stopA);
    }
        while(stopA>startA);
