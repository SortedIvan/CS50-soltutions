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
string encrypt_message(int key, string message, int length);

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

    // (int)'A' so we get its ASCII value
    // (p[i] - get its ascii value) - (int)'A'
    // ci = (p[i] + key) % 26
    // ci + 'A' = new place of the ciphered char

    int length = get_string_length(message);
    string encrypted_message = encrypt_message(key, message, length); // Looping through each character, getting its value and using the formula

    // Loop to printout every character in the message;
    printf("cipher text: ");
    for (int i = 0; i < length; i++)
    {
        printf("%c", encrypted_message[i]);
    }

    printf("\n");
    return 0;
}


string encrypt_message(int key, string message, int length){
    for (int i = 0; i < length; i++)
    { // E - 69
      // key = 40
      // ci = (pi + key) % 26
        int char_value = (int)message[i];
        if (char_value >= 65 && char_value <= 90)
        {
            int cipher_key = (int)message[i] - (int)'A';
            int cipher_formula = (cipher_key + key) % 26;
            message[i] = (char)(cipher_formula + (int)'A');
        }
        else if(char_value >= 97 && char_value <= 122)
        {
            int cipher_key = (int)message[i] - (int)'a';
            int cipher_formula = (cipher_key + key) % 26;
            message[i] = (char)(cipher_formula + (int)'a');
        }
    }
    return message;
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