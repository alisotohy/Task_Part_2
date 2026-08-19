#include <stdio.h>
int main ()
{
    int No;
    printf("please enter the no you want ");    
    scanf("%d",&No);
// in ex why msb for -1 is 1 as we use 2`s complement 
// we let the no of bit 8
//as read bit for MSB we take the bit no 7
    int MSB=1&(No>>7);
    printf("MSB is : %d",MSB);
}
