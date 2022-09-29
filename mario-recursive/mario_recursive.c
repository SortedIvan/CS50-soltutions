#include <cs50.h>
#include <stdio.h>


void draw_stairs(int height);

int main()
{

}

void draw_stairs(int height)
{

    draw_stairs(height - 1);

    for (int i = 0; i < height - 1; i++)
    {
        printf("#");
    }
    printf("\n");
}