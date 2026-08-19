#include <stdio.h>
int main ()
{
    int No,NTH;
    int Final_NO;

    printf("please enter the no you want ");    
    scanf("%d",&No);

    printf ("enter nth bit to set ");
    scanf("%d",&NTH);

    //we need to make the nth bit is = 1
    // as a set bit function
    Final_NO =No|(1<<NTH);
    printf("\n\nbit set sucsses\n");
    printf("the no was : %d\n",No);
    printf("the no be : %d",Final_NO);
    
}
