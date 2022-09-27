#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// ci = (pi + k) % 26 where:
// - pi is a character from the string we want to encrypt
// - ci is the encrypted character
// - k is the key

bool only_digits(string message);
int get_string_length(string message);

int main(int argc, string argv[]) // int argc, string argv[]
{

    if (argc != 2){
        printf("Usage: ./caesar {key}\n");
        return 1;
    }

    if (!only_digits(argv[1])){
        printf("Usage: ./caesar {key}\n");
        return 1;
    }
    int key = (int)strtol(argv[1], (char **)NULL, 10);
    string message = get_string("Provide a word to encrypt: ");

    



    return 0;
}

int get_string_length(string message){
    int k = 0;
    while (message[k] != '\0') // Simple way to count the characters in message
    {
        k++;
    }
    return k;
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