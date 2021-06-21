using namespace std;
#include <bits/stdc++.h>
#include<iostream>

int main()
{
    vector<int> nums = {1,2,3,4,5,6,7,8,9,10};

    int n = nums.size();

    vector<long int> pse(n + 5, 0);
    vector<long int> pso(n + 5, 0);
    vector<long int> sse(n + 5, 0);
    vector<long int> sso(n + 5, 0);

    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            pse[i + 1] = pse[i] + nums[i];
            pso[i + 1] = pso[i];
        }
        else
        {
            pse[i + 1] = pse[i];
            pso[i + 1] = pso[i] + nums[i];
        }
    }

    for (int i = n-1; i >= 0; i--)
    {
        if (i % 2 == 0)
        {
            sse[i+1] = sse[i + 2] + nums[i];
            sso[i+1] = sso[i + 2];
        }
        else
        {
            sse[i+1] = sse[i + 2];
            sso[i+1] = sso[i + 2] + nums[i];
        }
    }

    /*for(int i=0;i<n+5;i++)
        {
            cout<<prefix[i]<<" ";
        }
        
        cout<<"\n";
        
        for(int i=0;i<n+5;i++)
        {
            cout<<suffix[i]<<" ";
        }*/

    for (int i = 0; i < n + 5;i++)
        cout << pse[i] << " ";
    cout << endl;

    for (int i = 0; i < n + 5; i++)
        cout << pso[i] << " ";
    cout << endl;

    for (int i = 0; i < n + 5; i++)
        cout << sse[i] << " ";
    cout << endl;

    for (int i = 0; i < n + 5; i++)
        cout << sso[i] << " ";
    cout << endl;

    int ans = 0;

    for (int i = 1; i <= n; i++)
    {

        long int sume = pse[i - 1] + sso[i + 1];
        long int sumo = pso[i - 1] + sse[i + 1];

        if (sume == sumo)
            ans++;
    }

    cout << ans << endl;
}
