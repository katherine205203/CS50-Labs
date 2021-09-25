#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    float dollar;
    do
    {
        dollar = get_float("Enter the value: ");
    }
    while (dollar < 0);

    int cent = round(dollar * 100);


    int coin = 0;
    while (cent > 0)
    {
        if (cent >= 25)
        {
            cent = cent - 25;
            coin++;
        }
        else if (cent >= 10)
        {
            cent = cent - 10;
            coin++;
        }
        else if (cent >= 5)
        {
            cent = cent - 5;
            coin++;
        }
        else
        {
            cent = cent - 1;
            coin++;
        }
    }

    printf("Number of coins: %i\n", coin);

}
