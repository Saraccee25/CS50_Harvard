#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height = 0;

    //asking for height value
    do
    {
        height = get_int("Height: ");
    }
    //loops for the pyramids

    while (height < 1 || height > 8);

    for (int i = 0; i < height; i++)
    {
        for (int j = height - 1; j > i; j--) //this loop has the spaces of the first pyramid
        {
            printf(" ");
        }

        for (int k = 0; k <= i; k++) //hashes of fist pyramid
        {
            printf("#");
        }

        //spaces between the 2 of them
        printf("  ");

        for (int k = 0; k <= i; k++)
        {
            printf("#");
        }

        printf("\n");
    }
}