#include <cs50.h>
#include <stdio.h>

int get_n1(long number);
int get_n2(long number);
int get_n3(long number);
int get_n4(long number);
int get_n5(long number);
int get_n6(long number);
int get_n7(long number);
int get_n8(long number);
int get_n9(long number);
int get_n10(long number);
int get_n11(long number);
int get_n12(long number);
int get_n13(long number);
int get_n14(long number);
int get_n15(long number);
int get_n16(long number);
int get_n16_A(long number);

int main(void)
{
    long number;
    long test;
    do
    {
        number = get_long("Card number: ");
        test = number / 10000000000000000;
    }
    while (test > 0 || number < 1);

    int n1 = get_n1(number);
    int n2 = get_n2(number);
    int n3 = get_n3(number);
    int n4 = get_n4(number);
    int n5 = get_n5(number);
    int n6 = get_n6(number);
    int n7 = get_n7(number);
    int n8 = get_n8(number);
    int n9 = get_n9(number);
    int n10 = get_n10(number);
    int n11 = get_n11(number);
    int n12 = get_n12(number);
    int n13 = get_n13(number);
    int n14 = get_n14(number);
    int n15 = get_n15(number);
    int n16 = get_n16(number);
    int n16_A = get_n16_A(number);

    int even_total = n2 + n4 + n6 + n8 + n10 + n12 + n14 + n16;
    int odd_total = n1 + n3 + n5 + n7 + n9 + n11 + n13 + n15;
    int total = even_total + odd_total;
    int luhn_test = total % 10;

    printf("%i\n", luhn_test);

    if (luhn_test != 0)
    {
        printf("INVALID\n");
    }
    else
    {
        if (n16 == 0 && n15 != 0)
        {
            printf("AMEX\n");
        }
        else
        {
            if (n16 + n15 + n14 == 0)
            {
                printf("VISA\n");
            }
            else
            {
                if (n16_A == 4)
                {
                    printf("VISA\n");
                }
                else
                {
                    printf("MASTERCARD\n");
                }
            }

        }

    }

}

int get_n1(long number)
{
    int n1 = number % 10;
    return n1;
}

int get_n2(long number)
{
    int n2 = number % 100;
    n2 = n2 / 10;
    n2 = n2 * 2;
    n2 = (n2 % 10) + (n2 / 10);
    return n2;
}

int get_n3(long number)
{
    int n3 = number % 1000;
    n3 = n3 / 100;
    return n3;
}

int get_n4(long number)
{
    int n4 = number % 10000;
    n4 = n4 / 1000;
    n4 = n4 * 2;
    n4 = (n4 % 10) + (n4 / 10);
    return n4;
}

int get_n5(long number)
{
    int n5 = number % 100000;
    n5 = n5 / 10000;
    return n5;
}

int get_n6(long number)
{
    int n6 = number % 1000000;
    n6 = n6 / 100000;
    n6 = n6 * 2;
    n6 = (n6 % 10) + (n6 / 10);
    return n6;
}

int get_n7(long number)
{
    int n7 = number % 10000000;
    n7 = n7 / 1000000;
    return n7;
}

int get_n8(long number)
{
    int n8 = number % 100000000;
    n8 = n8 / 10000000;
    n8 = n8 * 2;
    n8 = (n8 % 10) + (n8 / 10);
    return n8;
}

int get_n9(long number)
{
    long n9 = number % 1000000000;
    n9 = n9 / 100000000;
    return n9;
}

int get_n10(long number)
{
    long n10 = number % 10000000000;
    n10 = n10 / 1000000000;
    n10 = n10 * 2;
    n10 = (n10 % 10) + (n10 / 10);
    return n10;
}

int get_n11(long number)
{
    long n11 = number % 100000000000;
    n11 = n11 / 10000000000;
    return n11;
}

int get_n12(long number)
{
    long n12 = number % 1000000000000;
    n12 = n12 / 100000000000;
    n12 = n12 * 2;
    n12 = (n12 % 10) + (n12 / 10);
    return n12;
}

int get_n13(long number)
{
    long n13 = number % 10000000000000;
    n13 = n13 / 1000000000000;
    return n13;
}

int get_n14(long number)
{
    long n14 = number % 100000000000000;
    n14 = n14 / 10000000000000;
    n14 = n14 * 2;
    n14 = (n14 % 10) + (n14 / 10);
    return n14;
}

int get_n15(long number)
{
    long n15 = number % 1000000000000000;
    n15 = n15 / 100000000000000;
    return n15;
}

int get_n16(long number)
{
    long n16 = number % 10000000000000000;
    n16 = n16 / 1000000000000000;
    n16 = n16 * 2;
    n16 = (n16 % 10) + (n16 / 10);
    return n16;
}

int get_n16_A(long number)
{
    long n16_A = number % 10000000000000000;
    n16_A = n16_A / 1000000000000000;
    return n16_A;
}