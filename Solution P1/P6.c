    #include <stdio.h>
    int main ()
    {
        int no , Height_Bit=0,i,bit_state;
        printf("please enter the needded no ");
        scanf ("%d",&no);

        for(i=0;i<=7;i++)
        {
            bit_state=1&(no>>i);      //  MSB=1&(No>>i);

            if (bit_state==1)
            {
                Height_Bit=i;
            }
            else
            {

            }
        }
        printf("The Height Set Bit is : %d",Height_Bit);
    }