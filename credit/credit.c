#include <cs50.h>
#include <stdio.h>

bool validateCreditCard();

int main(void)
{
    if (validateCreditCard()){
        printf("Credit card is valid!\n");
        return 1;
    }
    printf("Try again!\n");
    return 0;
}

bool validateCreditCard()
{
    long credit = get_long("Enter your credit card nr: ");
    int sum = 0;

    4068 9
    while (credit > 0)  // for each odd digit
    {
        long digit = credit % 10;
        sum += digit;
        credit /= 10;

        long digit2 = credit % 10;
        digit2 *= 2;
        if (digit2 > 9){
            digit2 = digit2 - 9;
        }

        sum+= digit2;
        credit /= 10;
    }

    if (sum % 10 == 0) {
        return true;
    }
    return false;

}
