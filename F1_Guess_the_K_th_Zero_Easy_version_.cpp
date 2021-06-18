#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vc = vector<char>;
using vvc = vector<vc>;
const ll mod = 1e9 + 7, inf = 1e18;
#define pb push_back
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
int main()
{
    int n, t;
    cin >> n >> t; 
    int k;
    cin >> k;
    int l = 1, r = n, firstPos = n; 
    while (l <= r)
    {
        int mid = (l + r) / 2;
        int numOnes;
        cout << "?"
             << " " << 1 << " " << mid << endl;
        cin >> numOnes;
        int numZeros = mid - numOnes;
        if (numZeros >= k)
        {
            firstPos = mid;
            r = mid - 1; 
        }
        else
        {
            l = mid + 1; 
        }
    }
    cout << "!"
         << " " << firstPos;
    return 0;
}