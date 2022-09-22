#include <cs50.h>
#include <stdio.h>

int main(void)
{

}

bool validateCreditCard()
{
    long credit = get_long("Enter your credit card nr: ");

    int value = 123;
    while (value > 0) {
    int digit = value % 10;
    value /= 10;
    }

}