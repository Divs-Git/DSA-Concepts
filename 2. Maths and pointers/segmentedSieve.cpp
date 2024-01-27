#include <bits/stdc++.h>
using namespace std;

// Normal Seive of eratosthenes
vector<bool> Sieve(int n)
{

    vector<bool> prime(n + 1, true);

    prime[0] = prime[1] = false;

    for (int i = 2; i <= sqrt(n); i++)
    {
        if (prime[i])
        {
            int j = i * i;
            while (j <= n)
            {
                prime[j] = false;
                j += i;
            }
        }
    }
    return prime;
}

// Segmented Sieve
vector<bool> segSieveFind(int L, int R)
{
    // give me a prime array, i will mark it as seg sieve
    vector<bool> sieve = Sieve(sqrt(R));
    vector<int> basePrimes;

    for (int i = 0; i < sieve.size(); i++)
    {
        if (sieve[i])
        {
            basePrimes.push_back(i);
        }
    }

    vector<bool> segSieve(R - L + 1, true);

    if (L == 1 || L == 0)
    {
        segSieve[L] = false;
    }

    for (auto prime : basePrimes)
    {
        int first_mul = (L / prime) * prime;
        if (first_mul < L)
        {
            first_mul += prime;
        }

        int j = max(first_mul, prime * prime);
        while (j <= R)
        {
            segSieve[j - L] = false;
            j += prime;
        }
    }
    return segSieve;
}

int main()
{
    // vector<bool> arr = Sieve(30);

    // for(int i = 0 ; i < arr.size() ; i++) {
    //     if(arr[i]) {
    //         cout << i << " ";
    //     }
    // }

    vector<bool> arr = segSieveFind(110, 130);

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i])
        {
            cout << i + 110 << " ";
        }
    }
    return 0;
}