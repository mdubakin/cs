#include <stdio.h>

char *f = "false\n";
char *t = "true\n";

void print_string(char *str)
{
    putchar(*str);
    str++;
    if (*str != '\0')
    {
        print_string(str);
    }
}

void print_bool(int b)
{
    if (!b)
    {
        return print_string(f);
    }
    return print_string(t);
}

int main(void)
{
    print_bool(-100);
    print_bool(0);
    print_bool(100);
    return 0;
}
