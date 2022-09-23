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
    while (credit > 0)  // for each odd digit
    {
        long digit = credit % 10;
        printf("%ld\n", digit);
        sum += digit;
        credit /= 10;

        long digit2 = credit % 10;
        if (digit2 > 9){
            digit2 = digit2 - 9;
        }
        sum+= digit2;
        credit /= 10;
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