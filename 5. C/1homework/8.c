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

int max4(int a, int b, int c, int d)
{
    int _max = max2(a, b);
    _max = max2(_max, c);
    return max2(_max, d);
}

int main(void)
{
    printf("1, 2, 1, 3: %d\n", max4(1, 2, 1, 3));
    printf("6, 5, 4, 3: %d\n", max4(6, 5, 4, 3));
    printf("7, 9, 8, 6: %d\n", max4(7, 9, 8, 6));
    printf("0, 0, 0, 0: %d\n", max4(0, 0, 0, 0));
    return 0;
}
