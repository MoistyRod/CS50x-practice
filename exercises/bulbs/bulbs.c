#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    // TODO
    string word = get_string("Word: ");

    int char_position = 0;
    int char_decimal = word[0];

    while (char_decimal != 0)
    {
        int i;
        int power = 1;
        for (i = 0; i < 8; i++)
        {
            if (char_decimal >= (128 / power))
            {
                print_bulb(1);
                char_decimal = char_decimal - (128 / power);
            }
            else
            {
                print_bulb(0);
            }
            power = power * 2;
        }

        printf("\n");
        char_position ++;
        char_decimal = word[char_position];
    }

}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
