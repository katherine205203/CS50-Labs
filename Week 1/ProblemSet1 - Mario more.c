#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //Get number from user
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);
    
    
    for (int i = 0; i < n; i++)
    {
        //Left side pyramid
        for (int j = n - 1; j > i; j--)
        {
            printf(" ");
        }
        
        for (int k = -1; k < i; k++)
        {
            printf("#");
        }
        
        //Print space
        printf("  ");
      
        //Right side pyramid
        for (int m = -1; m < i; m++)
        {
            printf("#");
        }
        printf("\n");
    }
}
