#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size

    int start, pop=0, end;

    do{
        start = get_int("Start size: ");
    }while(start<9);

    // TODO: Prompt for end size

    do{
        end = get_int("End size: ");
    }while(end<start);

    // TODO: Calculate number of years until we reach threshold

    while(start<end){
        start += (int)(start / 3) - (int)(start/4);
        pop++;
    }

    // TODO: Print number of years

    printf("Years: %i\n", pop);
}