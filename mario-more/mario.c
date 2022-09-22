#include <cs50.h>
#include <stdio.h>

void marioRight(void);
void marioLeft(void);
void marioHard(void);


int main(void)
{
    marioHard();
}

void marioRight(void)
{
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

    for (int i = 1; i <= height; i++)
    {
        for (int k = height - i; k > 0; k--){
            printf(".");
        }
        int j = 0;
        while (j < i){
            printf("#");
            j++;
        }
        printf("\n");
    }

}

void marioHard(void)
{
    int height = -1;
    do
    {
        height = get_int("Enter height: ");
    }
    while (height < 0);

    for(int row = 1; row <= height; row++)
    {
        for (int k = height - row; k > 0; k--){
            printf(" ");
        }

        int j = 0;
        while (j < row){
            printf("#");
            j++;
        }

        printf(" ");

        for (int i = 0; i < row; i++){
            printf("#");
        }
        printf("\n");
    }
}