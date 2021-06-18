// C++ Program to compute the
// longest subarray with
// sum greater than equal to 0.
#include <bits/stdc++.h>
using namespace std;

// Function for the searching the
// starting index of the subarray
int search(int *searchspace, int s, int e, int key)
{
    // -1 signifies that no
    // starting point of the subarray
    // is not found with sum greater
    // than equal to 0.
    int ans = -1;

    // Binary search
    while (s <= e)
    {
        int mid = (s + e) / 2;

        if (searchspace[mid] - key >= 0)
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }

    return ans;
}

// Function to return the longest subarray
int longestSubarray(int a[], int n)
{
    // Array for the suffix sum
    // of the above the array.
    int SuffixSum[n + 1];
    SuffixSum[n] = 0;

    for (int i = n - 1; i >= 0; --i)
    {
        SuffixSum[i] = SuffixSum[i + 1] + a[i];
    }

    int ans = 0;

    // Search Space for potential starting
    // points of the subarray.
    // It will store the suffix sum
    // till i'th index in increasing order.
    int searchspace[n];

    // It will store the indexes
    // till which the suffix sum
    // is present in search space.
    int index[n];

    int j = 0;

    for (int i = 0; i < n; ++i)
    {

        // add the element to the search space if the j=0
        // or if the topmost element is lesser
        // than present suffix sum.
        if (j == 0 or SuffixSum[i] > searchspace[j - 1])
        {
            searchspace[j] = SuffixSum[i];
            index[j] = i;
            j++;
        }

        int idx = search(searchspace, 0, j - 1, SuffixSum[i + 1]);

        // Only when idx is not -1 an subarray is
        // possible with ending index at i.
        if (idx != -1)
            ans = max(ans, i - index[idx] + 1);
    }

    return ans;
}

// Driver Code
int main()
{
    int n;
    cin>>n;

    int a[n];

    for (int i = 0;i<n;i++)
        cin >> a[i];

        cout << longestSubarray(a, n);

    return 0;
}
