#include <stdio.h>

int is_zero(long a)
{
    long n = a;
    if (n == 0)
    {
        return 1;
    }
    else if (n != 0)
    {
        return 0;
    }
}

int my_is_zero(int a)
{
    return a == 0;
}

int main(void)
{
    printf("%d %d\n", is_zero(123), is_zero(0));

    printf("%d %d\n", my_is_zero(123), my_is_zero(0));
    return 0;
}
