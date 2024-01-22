#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int ans = 0;
    int i = 0;
    while (n != 0)
    {
        int bit = n & 1;
        ans = bit * round(pow(10, i)) + ans; // Generally round is used or float is used with pow
        n = n >> 1;
        i++;
    }

    cout <<ans;

    return 0;
}