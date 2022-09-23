#include <cs50.h>
#include <stdio.h>

bool validateCreditCard();

int main(void)
{
    validateCreditCard();
}

bool validateCreditCard()
{
    long credit = get_long("Enter your credit card nr: ");
    int sum = 0;

    credit /= 10;               // throw away the least significant digit
    while (credit > 0)  // for each odd digit
    {
        int digit = credit % 10;

        if (digit > 9){
            digit = digit - 9;
        }

        sum += digit;
        credit /= 100;          // throw away two digits
    }
    printf("%i", sum);
    return true;

}