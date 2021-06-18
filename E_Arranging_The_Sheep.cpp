// C++ Program to find the minimum
// number of jumps required to
// group all ones together in
// the binary string
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

// Function to get the
// minimum jump value
ll getMinJumps(string s)
{
    // Store all indices
    // of ones
    vector<ll> ones;

    ll jumps = 0, median = 0, ind = 0;

    // Populating one's indices
    for (ll i = 0; i < s.length(); i++)
    {
        if (s[i] == '*')
            ones.push_back(i);
    }

    if (ones.size() == 0)
        return jumps;

    // Calculate median
    median = ones[ones.size() / 2];
    ind = median;

    // Jumps required for 1's
    // to the left of median
    for (ll i = ind; i >= 0; i--)
    {
        if (s[i] == '*')
        {
            jumps += ind - i;
            ind--;
        }
    }
    ind = median;

    // Jumps required for 1's
    // to the right of median
    for (ll i = ind; i < s.length(); i++)
    {
        if (s[i] == '*')
        {
            jumps += i - ind;
            ind++;
        }
    }

    // Return the final answer
    return jumps;
}

// Driver Code
int main()
{
    ll t;
    cin>>t;
    while (t--)
    {
        ll n;
        cin>>n;

        string s;
        cin >> s;
        cout << getMinJumps(s) << '\n';
    }
    
    
    return 0;
}
