#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

const int TOTAL_LETTERS = 26;
const char SMALL_LETTERS[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
const char CAPITAL_LETTERS[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

bool iskeyalpha(string key, int length);
bool contains_repeated_ch(string key);
int get_lower_index(char ch);
int get_upper_index(char ch);

int main(int argc, string argv[])
{

    if (argc != 2)
    {
        printf("Usage: ./substitution    key\n");
        return 1;
    }

    int key_length = strlen(argv[1]);
    if (key_length != TOTAL_LETTERS)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    if(!iskeyalpha(argv[1], key_length))
    {
        printf("Key must only contain alphabetic characters.\n");
        return 1;
    }

    if(contains_repeated_ch(argv[1])) {
        printf("Key must not contain repeated characters.\n");
        return 1;
    }

    string plaintext = get_string("plaintext: ");

    printf("ciphertext: ");
    for(int i = 0, n = strlen(plaintext); i < n; i++) {
        char ch = plaintext[i];
        char result = '\0';
        if(isalpha(ch)) {
            if(islower(ch)) {
                int lower_index = get_lower_index(ch);
                char ch_in_key = argv[1][lower_index];
                result = isupper(ch_in_key) ? ch_in_key + 32 : ch_in_key;
            } else {
                int upper_index = get_upper_index(ch);
                char ch_in_key = argv[1][upper_index];
                result = islower(ch_in_key) ? ch_in_key - 32 : ch_in_key;
            }
        } else {
            result = ch;
        }
        printf("%c", result);
    }
    printf("\n");
    return 0;

}

int get_lower_index(char ch) {
    for(int i = 0; i < TOTAL_LETTERS; i++) {
        if(SMALL_LETTERS[i] == ch) {
            return i;
        }
    }
    return 0;
}

int get_upper_index(char ch) {
    for(int i = 0; i < TOTAL_LETTERS; i++) {
        if(CAPITAL_LETTERS[i] == ch) {
            return i;
        }
    }
    return 0;
}

bool iskeyalpha(string key, int length) {
    for(int i = 0; i < length; i++) {
        if(!isalpha(key[i]))
            return false;
    }
    return true;
}

bool contains_repeated_ch(string key) {
    for(int i = 0; i < TOTAL_LETTERS; i++) {
        for(int j = i + 1; j < TOTAL_LETTERS; j++) {
            if(key[i] == (isupper(key[j]) ? key[j] + 32 : key[j]) || key[i] == (islower(key[j]) ? key[j] - 32 : key[j])) {
                return true;
            }
        }
    }
    return false;
}
