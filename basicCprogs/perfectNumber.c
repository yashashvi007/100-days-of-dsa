#include <stdio.h>

void perfectNum(int num)
{
    int sum = 0;
    int rem;
    for (int i = 1; i < num; i++)
    {
        rem = num % i;
        if (rem == 0)
        {
            sum += i;
        }
    }

    if (sum == num)
    {
        printf("%d is a perfect number ", num);
    }
    else
    {
        printf("%d is not a perfect number", num);
    }
}

void perfectNumBetMinMax(int num)
{

    printf("Enter min : ");
    int min;
    scanf("%d", &min);
    printf("Enter max  : ");
    int max;
    scanf("%d", &max);
    for (int i = min; i <= max; i++)
    {
        int rem, sum = 0;
        for (int j = 1; j < i; j++)
        {
            rem = i % j;
            if (rem == 0)
            {
                sum += j;
            }
        }
        if (sum == i)
        {
            printf("%d\n", i);
        }
    }
}

int main()
{
    printf("Enter a Number : ");
    int num;
    scanf("%d", &num);
    // perfectNum(num);
    perfectNumBetMinMax(num);
}