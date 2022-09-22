#include <cs50.h>
#include <stdio.h>

void marioLeft(void);

int main(void)
{

    marioLeft();

}

void marioRight(void){
    int height = -1;
    do
    {
        height = get_int("Enter height:" );
    }
    while(height < 0);

    for (int i = 0; i < height; i++)
    {
        int count = i;

        while (count >= 0)
        {
            printf("#");
            count--;
        }
        printf("\n");
    }
}
// comment
void marioLeft(void)
{
    int height = -1;
    do
    {
        height = get_int("Enter height: ");
    }
    while (height < 0);

    for (int i = height; i > 0; i++)
    {
        int count = i - 1;
        while (i > 0)
        {
            
        }
    }
}