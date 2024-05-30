#include <stdio.h>

void relation_sign(int a, int b)
{
    if (a < b)
    {
        putchar('<');
    }
    else if (a == b)
    {
        putchar('=');
    }
    else if (a > b)
    {
        putchar('>');
    }
    return;
}

void my_relation_sign(int a, int b)
{
    char c = '=';
    if (a < b)
    {
        c = '<';
    }
    else if (a > b)
    {
        c = '>';
    }
    putchar(c);
    return;
}

int main(void)
{
    relation_sign(1, 2);
    relation_sign(1, 1);
    relation_sign(2, 1);

    putchar('\n');

    my_relation_sign(1, 2);
    my_relation_sign(1, 1);
    my_relation_sign(2, 1);
    return 0;
}
