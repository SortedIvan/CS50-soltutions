#include <cs50.h>
#include <stdio.h>


string encrypt_message(string message, string key);

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

    // A - 65
    // Z - 90
}

string encrypt_message(string message, string key)
{
    for(int i = 0; i < get_string_len(message); i++)
    {
        int alphabetic_pos = (int)message[i] - (int)'A';
        message[i] = key[alphabetic_pos];
        //NQXPOMAFTRHLZGECYJIUWSKDVB - key[i] = N
        // takes message[i] where it would usually sit in a normal alph order = key[i]
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