#include <stdio.h>

void print_string(char *str)
{
    putchar(*str);
    str++;
    if (*str != '\0')
    {
        print_string(str);
    }
}

int main(void)
{
    print_string("Hello, World!");
    return 0;
}
