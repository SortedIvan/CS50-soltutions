#include <cs50.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void sort_array(int unsorted_array[], int length);

int main()
{
    srand(time(NULL));
    int length = get_int("Provide array size:" );
    int unsorted_array[length];

    // Populating array with values between 1 and 19
    for (int i = 0; i < length; i++)
    {
        unsorted_array[i] = rand() % 20;
    }

    // Printing unsorted array
    printf("unsorted array: ");
    for (int i = 0; i < length; i++)
    {
        printf(" %i, ", unsorted_array[i]);
    }
    printf("\n");

    sort_array(unsorted_array, length);

}

void sort_array(int unsorted_array[], int length)
{
    int smallest_nr = unsorted_array[0];
    int sorted_array[length];
    int counter = 0;

    while (counter < length)
    {
        for(int i = 1; i < length - 1; i++)
        {
            printf("%i", unsorted_array[i]);
            if (unsorted_array[i] < smallest_nr)
            {
                smallest_nr = unsorted_array[i];
            }
        }

        sorted_array[counter] = smallest_nr;
        smallest_nr = 0;
        counter++;
    }
    for (int i = 0; i < length; i++)
    {
        printf(" %i, ", sorted_array[i]);
    }
    printf("\n");
}
