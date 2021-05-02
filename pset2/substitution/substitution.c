#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
int valid_key(string s);
int main(int argc,string argv[])
    {
        if(argc != 2 || valid_key(argv[1]) != 0 )
            {
                printf("invalid key\n enter exactly 26 letters without any space\n");
                return 1;

            }
        else
            {
                string plaintext = get_string("plaintext :");
                printf("ciphertext:");
                for (int x = 0, n = strlen(plaintext); x < n; x++)
                    {
                        if (plaintext[x] >= 65 && plaintext[x] <= 90)
                            {

                                printf("%c", toupper(argv[1][plaintext[x] - 65]) );

                            }
                        else
                            {
                                if (plaintext[x] >=97 && plaintext[x] <= 122)
                                    {

                                        printf("%c", tolower(argv[1][plaintext[x] - 97]) );
                                    }
                                else
                                    {
                                        printf("%c",plaintext[x]);
                                    }
                            }
                    }
                printf("\n");
                return 0;
            }

    }

int valid_key(string s)
    {
        int j=0;
        if (strlen(s) == 26)
            {

                for (int i = 0; i<26; i++)
                    {
                        if ( (s[i] >= 65 && s[i] <= 90) || (s[i] >=97 && s[i] <= 122) )
                            {
                                for (int k = 0; k < i; k++)
                                    {
                                        if (toupper(s[i]) == toupper(s[k]) )
                                            {
                                                j=1;
                                                break;
                                            }
                                    }
                            }


                        else
                            {
                                j = 1;
                                break;
                            }
                    }
            }
        else
            {
                j=1;
            }

    return j;

    }
