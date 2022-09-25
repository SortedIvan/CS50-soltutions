#include <cs50.h>
#include <stdio.h>

int TestFormula(string input, int key);

int main(int argc, string argv[])
{
    printf("%i", TestFormula(argv[0], argc));
}

int TestFormula(string input, int key){

    int encryptedASCII = 0;
    encryptedASCII = ((int)input[0] + key) % 26;
    return encryptedASCII;
}