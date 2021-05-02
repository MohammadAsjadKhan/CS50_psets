#include <cs50.h>
#include <stdio.h>
int dig_sum(int num)
    {   int sum=0;
    while(num!=0)
        {
            sum+=num%10;
            num=num/10;
        }
    return sum;
    }

int main(void)
{
    long long int n = get_long_long("Number: ");
    int sum=0;
    int sum_2=0;
    long long int temp=n;
    int i=1;
    int dig=0 ;
    int dig_1, dig_2, dig_3, dig_4;

    while(temp!=0)
    {   if((n/10000)==0)
        {
            printf("INVALID\n");

        }     //base case//

        if(temp/10000 == 0 && temp/1000!=0)    // storing useful initial digits for determining card type//
            {
                 dig_4 = temp;
                 dig_3 = temp/10;
                 dig_2 = temp/100;
                 dig_1 = temp/1000;   // dig->tot_digits,dig_1->first one digit,dig_2->first 2 digits ...//

            }

        if(i==1)
        {

            sum+=temp%10;

            temp=temp/10;
        }
        else
        {

            sum_2+=dig_sum((temp%10)*2);

            temp=temp/10;
        }

        i=i*-1;
        dig++;

    }

    int magic_num=sum+sum_2;
    if(magic_num%10==0)  {   //checking luhn's algo//

        if((dig>12 && dig<17) && (dig_1==4))
            {
                printf("VISA\n");
            }

        else if(dig==15 && (dig_2 == 34 || dig_2 == 37))
            {
                printf("AMEX\n");
            }
        else if(dig==16 &&((dig_2 > 50 && dig_2 < 56) || (dig_4 > 2220 && dig_4 < 2721)))
            {
                printf("MASTERCARD\n");
            }
        else if(dig==16 && dig_3==607)
            {
                printf("RUPAY\n");
            }
        else if((dig>15 && dig<20) && dig_2 == 62)
            {
                printf("China Union Pay\n");
            }
        else if(dig == 16 && (dig_4 > 3527 && dig_4 < 3590 ))
            {
                printf("JCB\n");
            }
        else printf("INVALID\n");

    }

    else{
        printf("INVALID\n");
        }

}
