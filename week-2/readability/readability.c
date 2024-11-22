#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");

    float avg_letters = (float)count_letters(text) / (float)count_words(text) * 100.0;
    float avg_sentences = (float)count_sentences(text) / (float)count_words(text) * 100.0;

    int index = round(0.0588 * avg_letters - 0.296 * avg_sentences - 15.8);

    if(index < 1) {
        printf("Before Grade 1\n");
    } else if(index < 16) {
        printf("Grade %i\n", index);
    } else {
        printf("Grade 16+\n");
    }
}

int count_letters(string text) {
    int letters = 0;
    for(int i = 0, n = strlen(text); i < n; i++) {
        if(isalpha(text[i]))
            letters ++;
    }

    return letters;
}

int count_words(string text) {
    int words = 1;
    for(int i = 0, n = strlen(text); i < n; i++) {
        if(isspace(text[i])) {
            words ++;
        }
    }

    return words;
}

int count_sentences(string text) {
    int sentences = 0;
    for(int i = 0, n = strlen(text); i < n; i++) {
        if(text[i] == '.' || text[i] == '!' || text[i] == '?') {
            sentences ++;
        }
    }

    return sentences;
}
