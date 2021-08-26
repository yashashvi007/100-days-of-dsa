#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define ll long long int

bool isValidIP(string str)

{

    if (str.length() > 3)

        return false;

    if (str.front() == '0' && str.length() > 1)

        return false;

    ll val = stoi(str);

    return val >= 0 && val <= 255;
}

void computeAllValidIPAdress(string &str, vector<string> &res)

{

    for (ll i = 1; i <= 3 && i < str.length(); i++)

    {

        string first = str.substr(0, i);

        if (isValidIP(first))

        {

            for (ll j = 1; j <= 3 && i + j < str.length(); j++)

            {

                string second = str.substr(i, j);

                if (isValidIP(second))

                {

                    for (ll k = 1; k <= 3 && i + j + k < str.length(); k++)

                    {

                        string third = str.substr(i + j, k);

                        string fourth = str.substr(i + j + k);

                        if (isValidIP(third) && isValidIP(fourth))

                        {

                            res.emplace_back(first + "." + second + "." + third + "." + fourth);
                        }
                    }
                }
            }
        }
    }
}

int main()

{

    string str;

    cin >> str;

    vector<string> res;

    computeAllValidIPAdress(str, res);

    for (auto i : res)

        cout << i << "\n";

    return 0;
}