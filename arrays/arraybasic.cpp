#include <stdio.h>

int main()
{
    // prints garbage value for each element
    // int ar[5];
    // for (int i = 0; i < 5; i++)
    // {
    //     printf("%d ", ar[i]);
    // }

    int ar[5] = {1, 2, 3, 4, 5};
    // prints addresses
    // for (int i = 0; i < 5; i++)
    // {
    //     printf("%u ", &ar[i]);
    // }

    for (int i = 0; i < 5; i++)
    {
        printf("%d", *(ar + i));
    }
}