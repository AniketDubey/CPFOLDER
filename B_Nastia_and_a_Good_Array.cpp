#include <bits/stdc++.h>
#include <string>

using namespace std;

#define ll long long int
#define ld long double
#define pb push_back
#define all(v) v.begin(), v.end()
#define sz(x) ((int)(x).size())
#define deb(x) cout << #x << '=' << x << endl
#define MOD 1000000007

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        vector<pair<pair<ll, ll>, pair<ll, ll>>> ans;
        for (int i = 1; i < n; i += 2)
        {
            ans.pb({{i, i + 1}, {min(a[i - 1], a[i]), MOD}});
        }
        cout << sz(ans) << "\n";
        for (auto it : ans)
        {
            cout << it.first.first << " " << it.first.second << " " << it.second.first << " " << it.second.second << "\n";
        }
    }
    return 0;
}