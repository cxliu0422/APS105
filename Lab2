//part1
# include <stdio.h>
# include <math.h>
int main (void){
    printf("Enter the purchase price P: ");
    int inputprice;
    scanf("%d",&inputprice);
    printf("Enter the amount of down payment D: ");
    int inputpayment;
    scanf("%d",&inputpayment);
    printf("Enter the finance term (in months): ");
    int inputmonths;
    scanf("%d",&inputmonths);
    printf("Enter the monthly interest rate (in percent): ");
    double inputrate;
    scanf("%lf",&inputrate);
    double rateterm;
    rateterm= pow(1+inputrate/100,inputmonths);
    double outputpayment;
    outputpayment=((inputprice-inputpayment)*(inputrate/100)*rateterm)/(rateterm-1);
    printf("\nThe monthly payment is: %.2lf",outputpayment);
    return 0;
}

//part2
# include <stdio.h>
int main (void){
    printf("Enter an encrypted 4-digit combination: ");
    int inputnumber;
    scanf("%d",&inputnumber);
    int out1digits;
    out1digits=inputnumber/1000;
    int out2digits;
    out2digits=inputnumber/100-out1digits*10;
    int final2digits;
    final2digits=9-out2digits;
    int out3digits;
    out3digits=9-(inputnumber/10-out1digits*100-out2digits*10);
    int out4digits;
    out4digits=inputnumber%10;
    printf("The real combination is: %d%d%d%d",out4digits,final2digits,out3digits,out1digits);
    return 0;
}

//part3
# include <stdio.h>
int main (void){
    printf("Enter current time: ");
    int inputhour;
    int inputminutes;
    scanf("%d",&inputhour);
    scanf("%d",&inputminutes);
    printf("Enter trip time: \n");
    double triptime;
    scanf("%lf",&triptime);
    int arrivetimehours;
    arrivetimehours=inputhour+floor(triptime);
    int arrivetimeminutes;
    arrivetimeminutes=inputminutes+(triptime-floor(triptime))*60;
    if(arrivetimeminutes>=60){
        arrivetimeminutes=arrivetimeminutes-60;
        arrivetimehours=arrivetimehours+1;
    }
    else{
        arrivetimeminutes=arrivetimeminutes;
        arrivetimehours=arrivetimehours;
    }
    if(arrivetimehours>=24){
        int arrivenextday;
        arrivenextday=arrivetimehours-24;
        printf("Current time is %d:%d",inputhour,inputminutes);
        printf("\nArrival Time is next day %02d:%d", arrivenextday, arrivetimeminutes);
    }
    else{
        printf("Current time is %d:%d",inputhour,inputminutes);
        printf("\nArrival Time is same day %d:%d", arrivetimehours, arrivetimeminutes);
    }
    return 0;
}
