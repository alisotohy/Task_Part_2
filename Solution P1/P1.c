#include<stdio.h>
int main()
{
   //it is solve is easy why as if the lsb is 0 its even
   //but with bit wise you need you can solve it with yourself (-_-)
   int No;
   printf("please enter the no you want ");
   scanf("%d",&No);

   if (No%2==0)
   {
      printf("LSB is 0");
   }
   else
   {
      printf("LSB is 1");
   }
}
