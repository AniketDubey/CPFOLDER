#include <bits/stdc++.h>
#include <string>
#include <cmath>

using namespace std;

#define ll long long int
#define ld long double
#define loop(i, n) for (int i = 0; i < n; i++)
#define loops(i, s, n) for (int i = s; i < n; i++)
#define pb push_back
#define mp make_pair
#define all(v) v.begin(), v.end()
#define sz(x) ((int)(x).size())
#define fi first
#define se second
#define deb(x) cout << #x << '=' << x << endl
#define MOD 1000000007
const ll N = 1e7 + 1;
ll primes[N], vis[N], cnt[N];
map<ll, ll> m;
void seive()
{
    primes[1] = 0;
    vis[1] = 0;
    vis[0] = 0;
    for (ll i = 2; i <= N; i++)
    {
        primes[i] = primes[i - 1];
        if (vis[i])
        {
            for (ll j = 1; j * i <= N; j++)
            {
                primes[i] += cnt[i * j];
                vis[i * j] = 0;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    fill(vis, vis + N, 1);
    int n;
    cin >> n;
    ll a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
    }
    seive();
    int m;
    cin >> m;
    while (m--)
    {
        ll l, r;
        cin >> l >> r;
        l = min(N, l);
        r = min(N, r);
        cout << primes[r] - primes[l - 1] << "\n";
    }
}