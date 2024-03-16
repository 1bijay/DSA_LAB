#include <stdio.h>
#include <math.h>
int gcd(int p, int q)
{
    if (q == 0)
    {
        return p;
    }
    else
    {
        return gcd(q, p % q);
    }
}

int main()
{
    int x, y, result;
    printf("Enter the numbers to find GCD:\n");
    scanf("%d%d", &x, &y);
    result = gcd(x, y);
    printf("The GCD of %d and %d is:%d", x, y, result);
    return 0;
}