#include <cs50.h>
#include <stdio.h>

void marioLeft(void);

int main(void)
{

    marioLeft();

}

void marioRight(void){
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

void marioLeft(void){
    int height = -1;
    do{
        height = get_int("Enter height:" );
    }
    while(height < 0);

    for (int i = 0; i < height; i++){
        for (int j = 0; j < i; j++){
            printf(" ");
        }
    }

}