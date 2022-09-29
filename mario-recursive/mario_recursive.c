#include <cs50.h>
#include <stdio.h>


void draw_stairs(int height);

int main()
{

}

void draw_stairs(int height)
{
    for (int i = 0; i < height; i++)
    {
        printf("#");
    }
    draw_stairs(height - 1);
}