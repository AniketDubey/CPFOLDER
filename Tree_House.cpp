#define _USE_MATH_DEFINES
#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <math.h>
#include <set>
#include <string.h>
#include <map>
#include <queue>
#include <cmath>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

string en="\n";
string sp=" ";

/*******************************************************************************************/

#define mod 								1000000007
#define INF 								LLONG_MAX
#define NINF								LLONG_MIN
#define PII 								3.141592653589793238462643383279502884197169399375


#define vp(vi,x) 							cin>>x; 		vi.pb(x);		
#define bsearch(a,x)						binary_search(all(a),x)
#define LB(a,x) 							(std::lower_bound(all(a),x)-a.B)
#define UB(a,x) 							(std::upper_bound(all(a),x)-a.B)
#define smallest(a) 						*min_element(a.begin(),a.end())
#define largest(a) 							*max_element(a.begin(),a.end())
#define all(a) 								a.begin(), a.end()
#define sortdesc(a) 						sort(a.begin(),a.end(),greater<ll>())
#define ps(x, y) 							fixed << setprecision(y) << x
#define sz(a) 								(ll)a.size()
#define E 									end()
#define B 									begin()

/*******************************************************************************************/

#define yes 								cout<<"YES\n"
#define no 									cout<<"NO\n"
#define gcd 								__gcd
#define lcm(a,b)							((a*b)/__gcd(a,b))
#define ff 									first
#define ss 									second
#define pb 									push_back
#define mp 									make_pair
#define pii 								pair<ll, ll>
#define vi 									vector<ll>
#define mii 								map<ll,ll>
#define mci									map<char,ll>
#define msi									map<string,ll>
#define pqb 								priority_queue<ll>
#define pqs 								priority_queue<ll, vi, greater<ll>>

/*******************************************************************************************/
#define w(x)  								int x;    cin >> x; 	while (x--)
#define for0(i, n) 							for (ll i = 0; i < n; i++)
#define for1(i, n) 							for (ll i = 1; i <= n; i++)
#define loop(i, a, b) 						for (ll i = a; i < b; i++)
#define bloop(i, a, b) 						for (ll i = a; i >= b; i--)			
#define trav(g,arr)							for(auto g: arr) {cout<<g<<sp;} cout<<endl;
/*******************************************************************************************/

/*vi factor;
void fact(ll n)
{

    for(ll i=1;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            if(n/i==i)
                factor.pb(i);
            else
            {
                factor.pb(i);
                factor.pb(n/i);
            }
        }
    }

    sort(all(factor));
}*/

/*******************************************************************************************/

/*vi primenum;
void findprime(ll n)
{
    bool p[n+1];
    memset(p, true, sizeof(p));

    for (ll i = 2; i * i <= n; i++)
    {
        if (p[i] == true)
        {
            for (ll j = i * i; j <= n; j += i)
                p[j] = false;
        }
    }

    for (ll i = 2; i <= n; i++)
    {
        if (p[i] == true)
            primenum.pb(i);
    }

}*/

/*******************************************************************************************/

/*ll lcmofarray(vi arr)
{
    ll n = sz(arr);
    ll ans=1;
    for(ll i=0;i<n;i++)
    {
        ans = (arr[i]*ans)/(__gcd(arr[i],ans));
    }
    return ans;

}*/

/*******************************************************************************************/

/*ll gcdofarray(vi arr)
{
    ll n = sz(arr);
     ll ans=arr[0];
     for(ll i=1;i<n;i++)
            ans = __gcd(ans,arr[i]);
     return ans;
}*/

/*******************************************************************************************/

/*ll findgcd(ll a, ll b)
{

    if (b == 0)
        return a;
    return findgcd(b, a % b);

}*/

/*******************************************************************************************/

/*ll expomod(ll x,ll y,ll p)
{
    ll res=1;
    x = x%p;
    if(x==0)
        return 0;
    while(y>0)
    {
        if(y&1)
            res = ((res%p)*(x%p))%p;
        y=y>>1;
        x = ((x%p)*(x%p))%p;
    }
    return res;
}*/

/*******************************************************************************************/

/*ll ar[1000001];
void calc()
{
    ll maxn = 1000000;
    for (ll i = 1; i <= maxn; i++)
        ar[i] = -1;
        
    ar[1] = 1;
    for (ll i = 2; i <= maxn; i++)
    {
        if (ar[i] == -1)
        {
            for (ll j = i; j <= maxn; j = j + i)
            {
                if (ar[j] == -1)
                    ar[j] = i;
            }
        }
    }
}*/

/*******************************************************************************************/

/*ll phi(ll n) 
{ 
    ll result = n;  
   
    for(ll p = 2; p * p <= n; ++p) 
    { 
          
        if (n % p == 0)  
        { 
              
            while (n % p == 0) 
                n /= p; 
                  
            result -= result / p; 
        } 
    } 
   
    if (n > 1) 
        result -= result / n; 
          
    return result; 
}*/

/*******************************************************************************************/

/*ll Pow(ll a, ll x)
{
    if (x == 0)
        return 1;
    else
    {
        ll y = a;
        for (ll i = 1; i < x; i++)
        {
            a = a * y;
        }
        return a;
    }
}*/

/*******************************************************************************************/

vi arr[300100];

ll count1[300100] = {0};

ll ans[300100] = {0};

void numberOfNodes(ll s, ll e)
{
    //vector<ll>::iterator u;
    count1[s] = 1;
    for (ll g: arr[s])
    {
        if (g == e)
            continue;

        numberOfNodes(g, s);

        count1[s] += count1[g];
    }
}

void printNumberOfNodes(int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << "\nNodes in subtree of " << i;
        cout << ": " << count1[i];
    }
}

void dfs(ll s, ll e,ll x)
{
    vector<pair<ll,ll>> countofchild;

    //vector<ll>::iterator u;
    for (ll g: arr[s])
    {
        if (g == e)
            continue;
        else
            countofchild.pb(mp(count1[g],g));
    }
    

    sort(countofchild.rbegin(),countofchild.rend());

    /*for (auto g : countofchild)
        cout << g.ff << sp << g.ss << endl;*/

    ll start = x;
    //cout << "value of start -> " << start << endl;

    for0(i,sz(countofchild))
    {
        ll node = countofchild[i].ss;
        //ans[node] = ((start % mod + (start%mod * i%mod)%mod)%mod)%mod;
        //ans[node] = ans[node] % mod;
        ans[node] = (start + (start * i));
    }

    for (ll g: arr[s])
    {
        if (g == e)
            continue;
        else
            dfs(g, s, ans[g]);
        //dfs(g, s, ans[g]%mod);
        
    }

}

int main()
{
    IOS;

    w(t)
    {
        ll n,x;
        cin >> n >> x;

        vector<pair<ll, ll>> chutiya;

        //x = x % mod;

        for1(i,n-1)
        {
            ll x, y;
            cin >> x >> y;
            chutiya.pb(mp(x, y));
            
        }

        sort(all(chutiya));

        for(auto g: chutiya)
        {
            arr[g.ff].pb(g.ss);
            arr[g.ss].pb(g.ff);
        }

        numberOfNodes(1, 0);

        for1(i, n)
            count1[i] = count1[i] - 1;

        ans[1] = x;

        dfs(1, 0, ans[1]);

        ll aniket = 0;
        for1(i, n)
        {
            //cout << ans[i] << sp;
            aniket = (aniket%mod + ans[i]%mod)%mod;
           // aniket = aniket % mod;
        }

        //printNumberOfNodes(n);
        //cout << "\n";

        cout << (aniket % mod) << "\n";

        //printNumberOfNodes(n);
        for0(i, n+1)
        {
            arr[i].clear();
            count1[i] = 0;
            ans[i] = 0;
        }
            
        //cout << "\n#####################\n";
    }

    return 0;
}