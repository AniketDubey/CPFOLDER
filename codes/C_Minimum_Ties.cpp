#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define int long long
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define pii pair<int, int>
#define vi vector<int>
#define mii map<int, int>
#define pqb priority_queue<int>
#define pqs priority_queue<int, vi, greater<int>>
#define setbits(x) __builtin_popcountll(x)
#define mod 1000000007
#define inf 1e18
#define ps(x, y) fixed << setprecision(y) << x
#define mk(arr, n, type) type *arr = new type[n];
#define range(a, b) substr(a, b - a + 1)
#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)
#define trace(x) cerr << #x << ": " << x << " " << endl;
#define FIO                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


int32_t main()
{
    FIO;
    w(t)
    {
        int n;
        cin >> n;

        if (n % 2 == 0)
        {
            for (int i = 0; i < n; ++i)
                for (int j = i + 1; j < n; ++j)
                    if (i % 2 == 0 and j == i + 1)
                        cout << 0 << ' ';
                    else if ((i + j) & 1)
                        cout << -1 << ' ';
                    else
                        cout << 1 << ' ';
        }

        else
        {
            for (int i = 0; i < n; ++i)
                for (int j = i + 1; j < n; ++j)
                    if ((i + j) & 1)
                        cout << -1 << ' ';
                    else
                        cout << 1 << ' ';
        }

        cout << '\n';
    }

    return 0;
}