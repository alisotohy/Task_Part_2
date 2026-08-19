#include <stdio.h>
int main ()
{
    int no ,No_Left,No_Right,No_shift;
    printf("enter No");
    scanf("%d",&no);

    printf("enter No_shift");
    scanf("%d",&No_shift);

    No_Right=no>>No_shift;
    No_Left=no<<No_shift;

    printf("%d left rotated %d times = %d\n", no, No_shift,No_Left );

    printf("%d right rotated %d times = %d\n", no, No_shift, No_Right);
    

}

