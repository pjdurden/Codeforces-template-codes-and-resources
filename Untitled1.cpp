#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// Function to print
// first n Fibonacci Numbers
void printFibonacciNumbers(ll n)
{
    ll f1 = 0, f2 = 1, i;

    if (n < 1)
        return;
    cout << f1 << " ";
    for (i = 1; i < n; i++) {
        cout << f2 << ",";
        ll next = f1 + f2;
        f1 = f2;
        f2 = next;
    }
}

// Driver Code
int main()
{
    printFibonacciNumbers(55);
    return 0;
}
