#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll a, b;
        cin >> a >> b;
        if (a % b)
        {
            cout << a << endl;
            continue;
        }
        vector<ll> f;
        ll s = b;
        for (ll x = 2; x * x <= b; x++)
        {
            while (b % x == 0)
            {
                f.push_back(x);
                b /= x;
            }
        }
        if (b > 1)
            f.push_back(b);
        ll ans = 0;
        for (ll i = 0; i < f.size(); i++)
        {
            ll y = a;
            while (y % f[i] == 0)
            {
                y = y / f[i];
                if (y % s)
                {
                    ans = max(ans, y);
                    break;
                }
            }
        }
        cout << ans << endl;
    }
}