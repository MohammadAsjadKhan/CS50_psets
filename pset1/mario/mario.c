#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int h = get_int("Height: ");

    while(h <= 0 || h >= 9 ) h = get_int("Height: ");

        for(int i=1;h-i>=0;i++)
        {
            for(int j=h-i;j>0;j--)
                {
                    printf(" ");
                }
            for(int k=i;k>0;k--)
                {
                    printf("#");
                }
            printf("  ");

            for(int k=i;k>0;k--)
                {
                    printf("#");
                }
            printf("\n");
        }

    return 0;
}
