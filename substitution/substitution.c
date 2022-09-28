#include <cs50.h>
#include <stdio.h>
#include <ctype.h>


string encrypt_message(string message, string key);
int get_string_len(string string_message);
string decapitalize_message(string message);

int main(int argc, string argv[])
{
    if(argc != 2)
    {
        return 1;
        printf("Usage: ./substitution key");
    }

    string key = argv[1]; // sequence of how the alphabet is arranged
    string message = get_string("Provide a word to encrypt: ");
    string ciphered_message = encrypt_message(message, key);


    printf("Ciphered text: ");
    for (int i = 0; i < get_string_len(ciphered_message); i++)
    {
        printf("%c", message[i]);
    }
    printf("\n");

    // ASCII VALUES
    // A - 65
    // Z - 90
    // a - 97
    // z - 122
}

string encrypt_message(string message, string key)
{
    for(int i = 0; i < get_string_len(message); i++)
    {
        if (message[i] >= 65 && message[i] <= 90)
        {
            int alphabetic_pos = (int)message[i] - (int)'A';
            message[i] = key[alphabetic_pos];
        }
        else if (message[i] >= 97 && message[i] <= 122)
        {
            int alphabetic_pos = (int)message[i] - (int)'a';
            message[i] = key[alphabetic_pos];
            message[i] = tolower(message[i]);
        }

    }
    return message;
}

int get_string_len(string string_message)
{
    int i = 0;
    while (string_message[i] != '\0')
    {
        i++;
    }
    return i;
}

string decapitalize_message(string message)
{
    for (int i = 0; i < get_string_len(message); i++)
    {
        message[i] = tolower(message[i]);
    }
    return message;
}
