#include <cs50.h>
#include <stdio.h>


int main(void)
{

    //required variables
    long number = get_long("Number:"); //get the card number
    int sum = 0, last, second, s1, s2;
    long code = number;
    long holder = number;
    long size = number;
    int counter = 0;

    //count the digits
    while (size > 0)
    {
         size = size / 10;
         counter++;
    }


//perform validation
if (counter != 16 && counter != 15 && counter != 13)
    {
        printf("INVALID\n");
        return 0;
    }

//perform checksum
    do
    {


        last = holder % 10;
        holder = holder / 10;
        second = (holder % 10) * 2;
        s1 = second % 10;
        s2 = second / 10;

        holder = holder / 10;

        sum = sum + last + s1 + s2;
    }
    while (holder > 0);




    //validate and print the company name else "INVALID"
    if (sum % 10 == 0)
    {

        do
        {
            code = code / 10;
        }
        while (code > 100);

        if (code == 34 || code == 37)
        {

            printf("AMEX\n");
        }

        else if (code > 50 && code < 56)
        {
            printf("MASTERCARD\n");
        }

        else if (code / 10 == 4)
        {
            printf("VISA\n");
        }

        else
        {

            printf("INVALID\n");

        }


    }
    else
    {
        printf("INVALID\n");

    }



}