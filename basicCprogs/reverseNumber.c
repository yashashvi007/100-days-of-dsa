#include <stdio.h>

int main()
{
    int num;
    printf("Enter Number : ");
    scanf("%d", &num);
    int k, sum = 0;
    while (num != 0)
    {
        k = num % 10;
        sum = (sum * 10) + k;
        num = num / 10;
    }

    printf("%d\n", sum);
    return 0;
}