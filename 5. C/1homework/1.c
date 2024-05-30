#include <stdio.h>

int abs(int n)
{
    if (n >= 0)
    {
        return n;
    }
    return n * (-1);
}

int my_abs(int n)
{
    if (n < 0)
    {
        n *= -1;
    }
    return n;
}

int main(void)
{
    printf("%d\n", abs(-123));
    printf("%d\n", abs(123));
    printf("%d\n", my_abs(-456));
    printf("%d\n", my_abs(456));
    return 0;
}
