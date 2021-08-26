#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

struct Interval
{
    int start, end;
};

int comparator(Interval i1, Interval i2)
{
    return (i1.start < i2.start);
}

// void mergeIntervals(Interval arr[], int n)
// {
//     if (n == 0)
//         return;

//     sort(arr, arr + n, comparator);
//     stack<Interval> s;
//     s.push(arr[0]);

//     for (int i = 1; i < n; i++)
//     {
//         Interval top = s.top();
//         if (arr[i].start > top.end)
//         {
//             s.push(arr[i]);
//         }
//         else
//         {
//             top.end = arr[i].end;
//             s.pop();
//             s.push(top);
//         }
//     }

//     while (!s.empty())
//     {
//         Interval el = s.top();
//         s.pop();
//         cout << "[" << el.start << "," << el.end << "]";
//     }
// }

void mergeIntervals(Interval arr[], int n)
{
    if (n == 0)
        return;

    sort(arr, arr + n, comparator);

    int index = 0;

    for (int i = 1; i < n; i++)
    {
        if (arr[index].end > arr[i].start)
        {
            arr[index].end = max(arr[index].end, arr[i].end);
            arr[index].start = min(arr[index].start, arr[i].start);
        }
        else
        {
            index++;
            arr[index] = arr[i];
        }
    }

    for (int i = 0; i <= index; i++)
    {
        cout << "[" << arr[i].start << "," << arr[i].end << "]";
    }
}

int main()
{
    Interval arr[] = {{6, 8}, {1, 9}, {2, 4}, {4, 7}};
    int n = sizeof(arr) / sizeof(arr[0]);
    mergeIntervals(arr, n);
    return 0;
}