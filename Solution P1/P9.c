#include <stdio.h>
#include<stdint.h>

int main()
{
    uint32_t no, no_Zeros=0, Height_Bit=0, i, bit_state;

printf("please enter the needed no ");
scanf("%d",&no);

for(i=0;i<=7;i++)   //max bit is = 1
{
    bit_state = 1 & (no >> i);     // MSB = 1 & (No >> i);

    if (bit_state == 1)
    {
        Height_Bit = i;
    }
    else
    {

    }
}

//two ways

// 1:
for(i=Height_Bit;i<=31;i++)  // no zeros after MSB
{
    bit_state = 1 & (no >> i);     // MSB = 1 & (No >> i);

    if (bit_state == 1)
    {

    }
    else
    {
        no_Zeros++;
    }
}

printf("No of Zeros = %d\n\n",31-Height_Bit);

//2:
printf("No of Zeros = %d",no_Zeros);


}


