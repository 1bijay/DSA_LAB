
#include <stdio.h>
#include <math.h>

int expo(int m,int n)
{
    if (n == 0)
    {
        return 1;
    }
    return expo(m,n - 1)*m;
}

int main()
{
    int n,m;
    printf("Enter the number and power to raise :\n");
    scanf("%d%d",&m,&n);
    printf("Power of %d raise to %d is :%d",m, n, expo(m,n));
}