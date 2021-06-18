
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

#define mod 1000000007

#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)


ll modularexpo(ll x, ll y, ll p)
{
    ll res = 1;
    x = x % p;
    if (x == 0)
        return 0;
    while (y > 0)
    {
        if (y & 1)
            res = ((res % p) * (x % p)) % p;
        y = y >> 1;
        x = ((x % p) * (x % p)) % p;
    }
    return res;
}


int main()
{
    IOS;

    w(t)
    {
        ll n;
        cin >> n;

        cout << modularexpo(2, n - 1, mod) << "\n";
    }

    return 0;
}