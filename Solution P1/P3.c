#include <stdio.h>
int main ()
{
    int No,MSB,i;
    int No_Set =0;
    printf("please enter the no you want ");    
    scanf("%d",&No);
    //we need to read evey bit and the bit is = 1 +it to No_Set
    for (i=0;i<=7;i++)
    {
        MSB=1&(No>>i);
        if (MSB==1)
        {
            No_Set++;
        }
        else 
        {
            
        }
    }
    
    printf("NO of Set is : %d",No_Set);

}
