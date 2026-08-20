#include <stdio.h>
int main ()
{
    int No,pin_state;
    printf("enter Number : ");
    scanf("%d",&No);
    pin_state=1&(No<<0);
    if (pin_state==0)
    {
        printf("No %d is Even ",No);
    }
    else
    {
        printf("No %d is Odd ",No);        
    }

}