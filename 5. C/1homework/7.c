#include <stdio.h>
#include <stdbool.h>

int max2(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    return b;
}

int max3(int a, int b, int c)
{
    int _max = max2(a, b);
    return max2(_max, c);
}

int main(void)
{
    printf("1, 2, 3: %d\n", max3(1, 2, 3));
    printf("6, 5, 4: %d\n", max3(6, 5, 4));
    printf("7, 9, 8: %d\n", max3(7, 9, 8));
    printf("0, 0, 0: %d\n", max3(0, 0, 0));
    return 0;
}
