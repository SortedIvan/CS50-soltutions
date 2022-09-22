#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height = -1;
    do{
        height = get_int("Enter height:" );
    }
    while(height < 0);

    for (int i = 0; i < height; i++){
        int count = i;

        while (count >= 0){
            printf("#");
            count--;
        }
        printf("\n");
    }


}