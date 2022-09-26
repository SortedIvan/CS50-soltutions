#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// ci = (pi + k) % 26 where:
// - pi is a character from the string we want to encrypt
// - ci is the encrypted character
// - k is the key

bool only_digits(string message);

int main(int argc, string argv[]) // int argc, string argv[]
{
    // if (argc != 2 && !only_digits(argv[1])){
    //     printf("Usage: ./caesar {key}\n");
    //     return 1;
    // }

    string message = get_string("Provide a key: ");
    printf("%s", only_digits(message) ? "Correct key\n" : "Usage: ./caesar {key}\n");
}



// Function to chech whether a message consists of numbers or a string
bool only_digits(string message)
{
    int k = 0;
    while (message[k] != '\0') // Simple way to count the characters in message
    {
        k++;
    }

    for (int i = 0; i < k; i++)
    {
        if (!isdigit(message[i])){
            return false;
        }
        return true;
    }

    return true;
}