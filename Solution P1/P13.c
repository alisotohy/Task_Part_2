#include <stdio.h>
int main ()
{
    int N1,N2,Op;
    printf("enter no1 : ");
    scanf("%d",&N1);
    printf("enter no2 : ");
    scanf("%d",&N2);
    Op=N1;
    N1=N2;
    N2=Op;
    printf("\nNo 1 is : %d\n",N1);
    printf("No 2 is : %d",N2);


}