#include <stdio.h>
#include <stdint.h>

int main ()
{
    uint32_t No,i,Pin_State,arr[32];
    printf("enter Number : ");
    scanf("%d",&No);
    
    for (i=0;i<=31;i++)
    {
        arr[i]=1&(No>>i);
    }
    printf ("the binary no is : ");
    for ( i = 31; i >=0; i--)
    {
        printf("%d",arr[i]);
    }
    

}