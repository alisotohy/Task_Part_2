#include <stdio.h>
#include <stdint.h>
int main ()
{
    uint32_t no , Zeros_No=0,ones_No=0,i=0,state_pin;
    printf("please the no you want :");
    scanf("%d",&no);
    for(i=0;i<=31;i++)
    {
       state_pin = 1&(no>>i);
       if (state_pin==0)
       {
        Zeros_No++;
       }
       else
       {
        ones_No++;
       }
       
    }
    printf("\n\nthe no of zeros is : %d\n",Zeros_No);
    printf("the no of ones is : %d",ones_No);
    
}