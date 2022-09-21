#include <stdio.h>
#include <cs50.h>

int main(void){
    string answer = get_string("What my name bro? \n");
    printf("hello, %s \n", answer);
}