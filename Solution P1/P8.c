#include <stdio.h>
int main ()
{
    int no, no_Zeros=0,i,bit_state;
    printf("please enter the needded no ");
    scanf ("%d",&no);
    for(i=0;i<=7;i++)
        {
            bit_state=1&(no>>i);      //  MSB=1&(No>>i);

            if (bit_state==0)
            {
                no_Zeros++;
            }
            else
            {
                break;
            }
        }
    printf("NO Of Tralling Zeros is : %d",no_Zeros);
}