#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[0])
{
    typedef struct
    {
        char *word;
        int number;
    }
    word_list;

    word_list array[10];

    array[0].number = 3;
    array[1] = array[0].number;

    printf("%i\n", array[1].number);
}