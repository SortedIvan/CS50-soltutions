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
        printf("%i\n", digit);
        if (digit > 9){
            digit = digit - 9;
        }

        sum += digit;
        credit /= 100;
    }
    printf("%i\n", sum);
    return true;

}

        // int n, reverse=0, rem;
        // printf("Enter a number: ");
        // scanf("%d", &n);
        // while(n!=0)
        // {
        //     rem=n%10;
        //     reverse=reverse*10+rem;
        //     n/=10;
        // }