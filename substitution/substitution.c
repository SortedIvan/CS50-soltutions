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



    // A - 65
    // Z - 90
}

string encrypt_message(string message, string key)
{
    
}

