#include <stdio.h>
#include <stdbool.h>

bool check_char(unsigned char c)
{
    if (c - '0' < 0 ||
        c - 'A' < 0 ||
        c - 'a' < 0 ||
        c - 'a' > 15)
    {
        return false;
    }
    return true;
}

bool my_check_char(unsigned char c)
{
    return c >= 'a' && c <= 'p';
}

int main(void)
{
    printf("5: %d\n", check_char('5'));
    printf("Z: %d\n", check_char('Z'));
    printf("a: %d\n", check_char('a'));
    printf("e: %d\n", check_char('e'));
    printf("p: %d\n", check_char('p'));
    printf("q: %d\n", check_char('q'));

    putchar('\n');

    printf("5: %d\n", my_check_char('5'));
    printf("Z: %d\n", my_check_char('Z'));
    printf("a: %d\n", my_check_char('a'));
    printf("e: %d\n", my_check_char('e'));
    printf("p: %d\n", my_check_char('p'));
    printf("q: %d\n", my_check_char('q'));
    return 0;
}
