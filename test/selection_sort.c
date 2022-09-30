#include <cs50.h>
#include <stdio.h>

int get_array_size(int some_array[]);
void sort_array(int unsorted_array[]);

int main()
{
    int random_array[] = {1,3,4,5};
    printf("%i", get_array_size(random_array));
}

void sort_array(int unsorted_array[])
{

}

int get_array_size(int some_array[])
{
    int size = 0;
    while(some_array[size] != NULL)
    {
        size++;
    }
    return size;
}