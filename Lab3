//part1
# include <stdio.h>
# include <math.h>
# include <stdbool.h>
int main (void){
    printf("Enter the threshold in Celsius: ");
    int threshold;
    scanf("%d",&threshold);
    printf("Enter the observed boiling point in Celsius: ");
    int boilingpoint;
    scanf("%d",&boilingpoint);
if (boilingpoint<=100+threshold&&boilingpoint>=100-threshold){
    printf("The substance you tested is: Water");
}
else if (boilingpoint<=357+threshold&&boilingpoint>=357-threshold){
    printf("The substance you tested is: Mercury");
}
else if (boilingpoint<=1187+threshold&&boilingpoint>=1187-threshold){
    printf("The substance you tested is: Copper");
}
else if (boilingpoint<=2193+threshold&&boilingpoint>=2193-threshold){
    printf("The substance you tested is: Silver");
}
else if (boilingpoint<=2660+threshold&&boilingpoint>=2660-threshold){
    printf("The substance you tested is: Gold");
}
else{
    printf("Substance unknown.");
}
    return 0;
}

//part2
# include <stdio.h>
# include <math.h>
# include <stdbool.h>
int main (void){
    int inputrow;
    int inputcolumn;
    int rows;
    printf("Enter the number of rows in the triangle: ");
    scanf("%d",&rows);
    for(inputrow=1;inputrow<=rows;inputrow+=1){
        for(inputcolumn=inputrow;inputcolumn<rows;inputcolumn+=1){
            printf(" ");
        }
        for(inputcolumn=1;inputcolumn<=(2*inputrow-1);inputcolumn+=1){
            if(inputrow==rows||inputcolumn==1||inputcolumn==(2*inputrow-1)){
                printf("*");
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}

//part3
# include <stdio.h>
# include <math.h>
# include <stdbool.h>
int main (void){
    int money;
    printf("Please give an amount in cents less than 100: ");
    scanf("%d",&money);
    int cents;
    int nickels;
    int dimes;
    int quarters;
    const int centstonickels=5;
    const int centstodimes=10;
    const int centstoquarters=25;
    while(money>0&&money<100){
        printf("%d cents: ",money);
        quarters=money/centstoquarters;
        dimes=(money-centstoquarters*quarters)/centstodimes;
        nickels=(money-centstoquarters*quarters-centstodimes*dimes)/centstonickels;
        cents=money-centstoquarters*quarters-centstodimes*dimes-centstonickels*nickels;
        if(quarters>0){
            if(quarters==1){
                printf("%d quarter",quarters);

            }else if(quarters>1){
                printf("%d quarters",quarters);
            }
            if((dimes==0&&nickels==0&&cents!=0)||(dimes==0&&nickels!=0&&cents==0)||(dimes!=0&&nickels==0&&cents==0)){
                printf(" and ");
            }else if(dimes==0 && nickels==0 && cents==0){
                printf(".");
            }else{
                printf(", ");
            }
        }

        if(dimes>0){
            if(dimes==1){
            printf("%d dime",dimes);
            }
            else if(dimes>1){
            printf("%d dimes",dimes);
            }
            if((quarters!=0&&nickels==0&&cents==0)||(quarters==0&&nickels==0&&cents==0)){
                printf(".");
            }else if((quarters!=0&&nickels==0&&cents!=0)||(quarters!=0&&nickels!=0&&cents==0)){
                printf(", and ");
            }else if((quarters==0&&nickels==0&&cents!=0)||(quarters==0&&nickels!=0&&cents==0)){
                printf(" and ");
           
            }else{
                printf(", ");
            }
        }

        if(nickels>0){
            if(nickels==1){
            printf("%d nickel",nickels);
            }
            else if(nickels>1){
            printf("%d nickels",nickels);
            }
            if((quarters==0&&dimes!=0&&cents==0)||(quarters==0&&dimes==0&&cents==0)||(quarters!=0&&dimes==0&&cents==0)||(quarters!=0&&dimes!=0&&cents==0)){
                printf(".");
            }else if((quarters==0&&dimes==0&&cents!=0)){
                printf(" and ");
            }else if((quarters==0&&dimes!=0&&cents!=0)||(quarters!=0&&dimes==0&&cents!=0)||(quarters!=0&&dimes!=0&&cents!=0)){
                printf(", and ");
            }
        }
        if(cents>0){
            if(cents==1){
            printf("%d cent.",cents);
            }
            else if(cents>1){
            printf("%d cents.",cents);
            }
        }    
        printf("\nPlease give an amount in cents less than 100: ");
        scanf("%d",&money);
    }
    printf("%d cents: ",money);
    printf("invalid amount.");
    return 0;
}
