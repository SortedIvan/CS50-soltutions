#include <cs50.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define randnum(min, max) \ ((rand() % (int)(((max) + 1) - (min))) + (min))
void sort_array(int unsorted_array[], int length);

int main()
{
    srand(time(NULL));
    int length = get_int("Provide array size:" );
    int unsorted_array[length];

    // Populating array
    for (int i = 0; i < length; i++)
    {
        unsorted_array[i] = randnum(1,50);
    }

    // Printing unsorted array
    for (int i = 0; i < length; i++)
    {
        printf("%i", unsorted_array[i]);
    }
    printf("\n");


}

void sort_array(int unsorted_array[], int length)
{
    int smallest_nr = unsorted_array[0];
    int sorted_array[length];
    int counter = 0;




    while (counter <= length)
    {
        for(int i = 0; i < length; i++)
        {
            if (sorted_array[i] < smallest_nr)
            {
                smallest_nr = sorted_array[i];
            }
        }

        sorted_array[counter] = smallest_nr;
        counter++;
    }
    for (int i = 0; i < length; i++)
    {
        printf("%i", sorted_array[i]);
    }
    printf("\n");
}
