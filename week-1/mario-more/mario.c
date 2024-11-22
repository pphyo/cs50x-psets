#include <cs50.h>
#include <stdio.h>

int get_height(string prompt);

int main(void)

{
    int height = get_height("Height: ");

    for (int i = 0; i < height; i++) {
        for (int spaces = height - i - 2; spaces >= 0; spaces--) {
            printf(" ");
        }

        for (int left = 0; left <= i; left++) {
            printf("#");
        }

        printf("  ");

        for (int right = 0; right <= i; right++) {
            printf("#");
        }

        printf("\n");
    }
}

int get_height(string prompt)

{
    int number;
    do
    {
        number = get_int("%s", prompt);
    }
    while (number < 1 || number > 8);
    return number;
}
