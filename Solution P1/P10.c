#include<stdio.h>

int main ()
{
    int no , flip_no;
    printf("please enter a number you want to flip:  ");
    scanf("%d",&no);

    printf("the origin No : %d\n",no);


    flip_no=~no;
    printf("the flip No : %d",flip_no);

}