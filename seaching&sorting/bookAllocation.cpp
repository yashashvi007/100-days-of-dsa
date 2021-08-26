#include <iostream>
#include <vector>
using namespace std;

bool isPossible(int arr[], int n, int m, int min_pages)
{
    int pages = 0;
    int no_of_student = 1;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > min_pages)
        {
            return false;
        }

        if (arr[i] + pages > min_pages)
        {
            no_of_student++;

            pages = arr[i];

            if (no_of_student > m)
            {
                return false;
            }
        }
        else
        {
            pages += arr[i];
        }
    }

    return true;
}

int allocateBooks(int arr[], int n, int m)
{
    if (m > n)
    {
        return -1;
    }

    int start = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    int end = sum;

    int min_pages = 0;
    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (isPossible(arr, n, m, mid))
        {
            min_pages = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    return min_pages;
}

int main()
{
    int n;
    int arr[n];
    int m;
    //  vector<int> v;
    // for(int i=0;i<n;i++){
    //     int val;
    //     cin >> val;
    //     v.push_back(val);
    // }

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cin >> m;

    allocateBooks(arr, n);
    return 0;
}