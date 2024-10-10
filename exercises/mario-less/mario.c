#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int h;
    do
    {
        h = get_int("Height: ");
    }
    while (h < 1 || h > 8);

    for (int i = h; i > 0; i--)
    {
        int p = (i - 1);
        for (int j = p; j > 0; j--)
        {
            printf(" ");
        }

        for (int o = h - p; o > 0; o--)
        {
            printf("#");
        }

        printf(" ");

        for (int o = h - p; o > 0; o--)
        {
            printf("#");
        }

        printf("\n");
    }
}