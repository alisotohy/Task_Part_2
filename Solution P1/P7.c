    /*
    #include <stdio.h>
    int main ()
    {
        int no , lowest_Bit=0,i,bit_state;
        printf("please enter the needded no ");
        scanf ("%d",&no);

        //there is the best solution from thi but let`s try 
        //IAM TRYING a sswitch case in for but it soooooooooooooooooooooooooooooo long
        //but take a thing in my mind that am doing the same last problem by writing break
        //in the frist one i meet
        for(i=0;i>=7;i++)
        {
            switch (i)
            {
                case 0 : bit_state=1&(no>>i);      //  MSB=1&(No>>i);

                         if (bit_state==1)
                         {
                             lowest_Bit=i;
                         }
                         
                         printf("The lowest Set Bit is : %d",lowest_Bit);  break;
                case 1 : bit_state=1&(no>>i);      //  MSB=1&(No>>i);

                         if (bit_state==1)
                         {
                             lowest_Bit=i;
                         }
                         
                         printf("The lowest Set Bit is : %d",lowest_Bit);  break; 
                        
                case 2 : bit_state=1&(no>>i);    
                         if (bit_state==1)
                         {
                             lowest_Bit=i;
                         }
                         
                         printf("The lowest Set Bit is : %d",lowest_Bit);  break;         
        }   }
    }*/
   #include <stdio.h>
    int main ()
    {
        int no , lowest_Bit=0,i,bit_state;
        printf("please enter the needded no ");
        scanf ("%d",&no);

        for(i=0;i<=7;i++)
        {
            bit_state=1&(no>>i);      //  MSB=1&(No>>i);

            if (bit_state==1)
            {
                lowest_Bit=i; break;
            }
            else
            {

            }
        }
        printf("The lowest Set Bit is : %d",lowest_Bit);
    }