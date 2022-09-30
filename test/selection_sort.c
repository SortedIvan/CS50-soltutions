#include <cs50.h>
#include <stdio.h>

void sort_array(int unsorted_array[], int length);

int main()
{
    int length = get_int("Provide array size:" );

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
    }
}
