#include <iostream>
using namespace std;

int binarySearchIterative(int ar[], int first, int last, int target)
{
    int low = first;
    int high = last;
    while (first <= high)
    {
        int mid = (low + high) / 2;
        if (ar[mid] == target)
        {
            return mid;
        }
        else if (ar[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
}

int binarySearchRecursive(int ar[], int low, int high, int target)
{
    if (low <= high)
    {
        int mid = (low + high) / 2;
        if (ar[mid] == target)
        {
            return mid;
        }
        else if (ar[mid] < target)
        {
            return binarySearchRecursive(ar, mid + 1, high, target);
        }
        else
        {
            return binarySearchRecursive(ar, low, mid - 1, target);
        }
    }

    return -1;
}

int main()
{
    printf("Enter the number of elements in array : ");
    int n;
    scanf("%d", &n);
    int ar[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ar[i]);
    }

    printf("enter the target : ");
    int target;
    scanf("%d", &target);

    printf("%d", binarySearchIterative(ar, 0, n - 1, target));
}