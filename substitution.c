#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define ALPHABET_SIZE 26

bool is_valid_key(string key);
string encrypt(string plaintext, string key);

int main(int argc, string argv[])
{
    //Checking the command-line arguments

    if( argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    string key = argv[1];

     if (!is_valid_key(key))
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    // Get plaintext from the user
    string plaintext = get_string("plaintext: ");

    // Encrypt the plaintext using the key
    string ciphertext = encrypt(plaintext, key);

    // Print the ciphertext
    printf("ciphertext: %s\n", ciphertext);

    return 0;


}

// Function to check if the key is valid
bool is_valid_key(string key)
{
    int len = strlen(key);

    // The key must have exactly 26 characters
    if (len != ALPHABET_SIZE)
    {
        return false;
    }

    // Array to keep track of characters encountered in the key
    bool used_chars[ALPHABET_SIZE] = {false};

    for (int i = 0; i < len; i++)
    {
        char c = toupper(key[i]); // Convert character to uppercase

        // Check if the character is an alphabet
        if (!isalpha(c))
        {
            return false;
        }

        int index = c - 'A';

        // Check if the character is repeated in the key
        if (used_chars[index])
        {
            return false;
        }

        used_chars[index] = true;
    }

    return true;
}

// Function to encrypt the plaintext using the key
string encrypt(string plaintext, string key)
{
    int len = strlen(plaintext);
    string ciphertext = malloc(len + 1);

    for (int i = 0; i < len; i++)
    {
        char c = plaintext[i];
        char encrypted_char;

        if (isalpha(c))
        {
            // Convert the character to uppercase and get the index in the key
            int index = toupper(c) - 'A';
            encrypted_char = isupper(c) ? toupper(key[index]) : tolower(key[index]);
        }
        else
        {
            // If the character is not an alphabet, keep it as it is
            encrypted_char = c;
        }

        ciphertext[i] = encrypted_char;
    }

    ciphertext[len] = '\0'; // Null-terminate the ciphertext

    return ciphertext;
}