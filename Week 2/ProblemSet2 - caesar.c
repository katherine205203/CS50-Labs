#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    //Check there is only 1 arguments and it is a number else returns instructions
    if (argc == 2 && isdigit(*argv[1]))

    {
        //Get the ceasar KEY value convert into integar
        int k = atoi(argv[1]);

        //Get text
        string s = get_string("plaintext: ");

        //Print out cipher
        printf("ciphertext: ");

        //Iterate through plain text letter by letter
        for (int i = 0, n = strlen(s) ; i < n; i++)
        {
            //Checking if it is lowercase 97 = a to 112 = z and if it + 13 characters along.
            if (s[i] >= 'a' && s[i] <= 'z')
            {
                printf("%c", (((s[i] - 'a') + k) % 26) + 'a');
            }

            //If it it between uppercase A and C
            else if (s[i] >= 'A' && s[i] <= 'Z')
            {
                printf("%c", (((s[i] - 'A') + k) % 26) + 'A');
            }

            else
            {
                printf("%c", s[i]);
            }
        }

        printf("\n");
        return 0;
    }

    else
    {
        printf("Usage: ./caesar k\n");
        return 1;
    }
}
