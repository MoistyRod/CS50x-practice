#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int population;
    int end;
    int year = 0;
    int growth;
    int death;

    do
    {
        population = get_int("Start Size: ");
    }
    while (population < 9);

    do
    {
        end = get_int("End Size: ");
    }
    while (end < population);

    while (population < end)
    {
        growth = population / 3;
        death = population / 4;
        population = population + growth - death;
        year ++;
    }

    printf("%i\n", year);
}
