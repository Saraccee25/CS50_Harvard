#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Getting card number
    long long cc = get_long_long("Number: ");
    long long initialCC = cc;

    int digitCount = 0;
    int sum = 0;
    int psum = 0;
    int lastdigit = 0;

    while (cc > 0)
    {
        // Getting the last digit and incrementing the amount of digits
        lastdigit = cc % 10;
        digitCount++;

        // Verifying if the multiplication should be done
        if (digitCount % 2 == 0)
        {
            int aux = lastdigit * 2;
            psum += aux / 10 + aux % 10;
        }
        else
        {
            //adding up
            sum += lastdigit;
        }

        cc /= 10;
    }
    //verifying if the card is valid
    int tsum = sum + psum;
    bool isvalid = false;

    if (tsum % 10 == 0)
    {
        isvalid = true;
    }

    if (isvalid)
    {
        // Check the number of digits and starting digits to determine the card type
        if ((digitCount == 13 || digitCount == 16) && (initialCC / 1000000000000 == 4 || initialCC / 1000000000000000 == 4))
        {
            printf("VISA\n");
        }
        else if (digitCount == 16 && initialCC / 100000000000000 >= 51 && initialCC / 100000000000000 <= 55)
        {
            printf("MASTERCARD\n");
        }
        else if (digitCount == 15 && (initialCC / 10000000000000 == 34 || initialCC / 10000000000000 == 37))
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        //the card is not valid
        printf("INVALID\n");
    }
}