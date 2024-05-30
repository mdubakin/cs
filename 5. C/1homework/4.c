#include <stdio.h>

void print_hex_byte(int n)
{
    char d1 = (n / 16) + '0';
    char d2 = (n % 16) + '0';

    if (d1 > '9')
    {
        d1 += 'a' - 10 - '0';
    }
    putchar(d1);

    if (d2 > '9')
    {
        d2 += 'a' - 10 - '0';
    }
    putchar(d2);
}

int main(void)
{
    print_hex_byte(0);
    putchar('\n');
    print_hex_byte(1);
    putchar('\n');
    print_hex_byte(16);
    putchar('\n');
    print_hex_byte(200);
    putchar('\n');
    print_hex_byte(255);
    putchar('\n');
    return 0;
}
