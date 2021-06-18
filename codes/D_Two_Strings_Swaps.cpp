#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <unordered_map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <bitset>
#include <deque>
#include <string>
#include <list>
#include <iterator>
#include <sstream>
#include <algorithm>
#include <math.h>
#define lli long long int
#define lower(a) transform(a.begin(), a.end(), a.begin(), ::tolower);

using namespace std;

const int N = 3e5 + 500;
const long long mod = 1e9 + 7;
const long long cmod = 998244353;
const long long inf = 1LL << 61;
const int M = 1e6 + 500;
const lli ths = 1LL << 40;
const int NN = 5e3 + 6;

lli cnt1[40], cnt2[40];
bool vis[60];

void solve()
{
    lli n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    vector<pair<lli, lli>> ans;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == t[i])
            continue;
        bool ok = 0;
        for (int j = i + 1; j < n; j++)
        {
            if (s[i] == s[j])
            {
                swap(t[i], s[j]);
                ok = 1;
                // ans.push_back({i, j});
                ans.push_back({j, i});
                break;
            }
        }
        if (ok)
            continue;
        for (int j = i + 1; j < n; j++)
        {
            if (s[i] == t[j])
            {
                swap(s[j], t[j]);

                ans.push_back({j, j});
                swap(t[i], s[j]);
                ans.push_back({j, i});
                ok = 1;
                break;
            }
        }
        if (ok == 0)
        {
            cout << "NO\n";
            return;
        }
    }
    cout << ans.size() << endl;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
