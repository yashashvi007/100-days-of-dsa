#include <bits/stdc++.h>
using namespace std;

// int lcs(char *X, char *Y, int n, int m)
// {
//     if (n == 0 || m == 0)
//     {
//         return 0;
//     }
//     else if (X[n - 1] == Y[m - 1])
//     {
//         return 1 + lcs(X, Y, n - 1, m - 1);
//     }
//     else
//     {
//         return max(lcs(X, Y, n - 1, m), lcs(X, Y, n, m - 1));
//     }
// }



int main()
{
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";

    int n = strlen(X);
    int m = strlen(Y);

    cout << lcs(X, Y, n, m);
    return 0;
}