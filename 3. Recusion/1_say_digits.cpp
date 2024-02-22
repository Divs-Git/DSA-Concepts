#include <bits/stdc++.h>
using namespace std;

void sayDigits(string arr[], int n)
{

  // Base case
  if (n == 0)
  {
    cout << "zero";
    return;
  }

  // Recursive case
  int digit = n % 10;
  n = n / 10;

  sayDigits(arr, n);

  cout << arr[digit] << " ";
}

int main()
{
  int n;
  cin >> n;

  string arr[10] = {"zero",
                    "one",
                    "two",
                    "three",
                    "four",
                    "five",
                    "six",
                    "seven",
                    "eight",
                    "nine"};

  sayDigits(arr, n);
  return 0;
}