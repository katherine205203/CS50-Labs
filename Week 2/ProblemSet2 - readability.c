#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include <stdio.h>

int main(void)
{
    //Counting variables
    int letter = 0;
    int word = 1;
    int sentence = 0;

    //Take input from user
    string text = get_string("Text: ");


    for (int i = 0; i < strlen(text); i++)
    {
        //Counting letters
        if ((text[i] >= 'A' && text[i] <= 'Z') || (text[i] >= 'a' && text[i] <= 'z'))
        {
            letter++;
        }

        //Counting words
        if (text[i] == ' ')
        {
            word++;
        }

        //Counting sentences
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentence++;
        }
    }

    //Coleman-Liau Index
    float L = (((float)letter / (float)word) * 100);
    float S = (((float)sentence / (float)word) * 100);
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    //Print result
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}
