#include <cs50.h>
#include <stdio.h>

bool validateCreditCard();

int main(void)
{

}

bool validateCreditCard()
{
    long credit = get_long("Enter your credit card nr: ");
    sum = 0;
    
    credit /= 10;               // throw away the least significant digit
    for (int i = 0; i < 7; ++i)  // for each odd digit
    {
        digits[i] = cardNum %10; // extract the digit
        cardNum /= 100;          // throw away two digits
    }

}