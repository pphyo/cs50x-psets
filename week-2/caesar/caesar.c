#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool is_numeric(string key);
int rotate(char c, int key);

int main(int argc, string argv[])
{

    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    if (!is_numeric(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int key = atoi(argv[1]);

    string plaintext = get_string("plaintext: ");

    printf("ciphertext: ");

    int lenght_text = strlen(plaintext);

    for (int i = 0; i < lenght_text; i++)
    {
        printf("%c", rotate(plaintext[i], key));
    }
    printf("\n");
}

int rotate(char c, int key)
{

    if (isalpha(c))
    {
        if (isupper(c))
        {
            return (c - 65 + key) % 26 + 65;
        }

        else
        {
            return (c - 97 + key) % 26 + 97;
        }
    }
    else
    {
        return c;
    }
}

bool is_numeric(string s)
{
    for (int i = 0; i < strlen(s); i++) {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}
