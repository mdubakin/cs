#include <stdio.h>
#include <stdbool.h>

// что-то не работает :)
char convert_char(unsigned char c)
{
    c -= '0';
    if (c < 10)
    {
        return c;
    }
    c += '0';
    c -= 'A' - 10;
    if (c < 16)
    {
        return c;
    }
    c += 'A';
    c -= 'a';
    return c;
}

char my_convert_char(unsigned char c)
{
    bool lower = c >= 97 && c <= 122;
    bool upper = c >= 65 && c <= 90;
    if (lower)
    {
        return c - ('a' - 'A');
    }
    if (upper)
    {
        return c + ('a' - 'A');
    }
    return c;
}

int main(void)
{
    printf("1: %c\n", convert_char('a'));
    printf("2: %c\n", convert_char('B'));
    printf("3: %c\n", convert_char(' '));
    printf("4: %c\n", convert_char('0'));

    putchar('\n');

    printf("1: %c\n", my_convert_char('a'));
    printf("2: %c\n", my_convert_char('B'));
    printf("3: %c\n", my_convert_char(' '));
    printf("4: %c\n", my_convert_char('0'));
    return 0;
}
