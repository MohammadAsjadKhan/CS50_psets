#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int main(void)
    {
        string text = get_string("Text: ");
        double words= 1.00, letters = 0.00, sentences = 1.000 ;
        double L, S, index;                              //l-> # avg letters per 100 words, S-> # avg sentences per 100 words.

        int n = strlen(text);
        for(int i = n - 1; i >= 0; i--)
        {
            char c = text[i];
            if ( (c >= 65 && c <= 90) || (c >= 97 && c <= 122) ) break;
            else n--;
        }
        int start = 0;
        for(int i = 0; i < n; i++)
        {
            char c = text[i];
            if ( (c >= 65 && c <= 90) || (c >= 97 && c <= 122) ) break;
            else start++;
        }
        for (int i = start; i < n; i++)
            {
                char c = text[i];
                if (c == ' ' && text[i - 1] != ' ') words++;

                if ( (c >= 65 && c <= 90) || (c >= 97 && c <= 122) ) letters++;

                if ( (c == '.' || c == '!') || c == '?' ) sentences++;

            }

        L = (letters/words)*100;
        S = (sentences/words)*100;

        index = 0.0588 * L - 0.296 * S - 15.8;
        int Grade = round(index);
        if(Grade < 1)
            {
                printf("Before Grade 1\n");
            }

        else if (Grade >= 16)
            {
                        printf("Grade 16+\n");
            }
        else
            {
                printf("Grade %d\n",Grade);
            }

    }
