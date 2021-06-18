#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{

    int arr[] = {2, -1, -10, 5, 8, 98};
    int brr[] = {45, 98, -98, 45, 0, -2};

    int size_arr = sizeof(arr) / sizeof(arr[0]);
    int size_brr = sizeof(brr) / sizeof(brr[0]);

    //cout << size_arr << " " << size_brr << endl;

    sort(arr, arr + size_arr);
    sort(brr, brr + size_brr);

    /* for (auto g : arr)
        cout << g << " ";
    cout << endl;

    for (auto g : brr)
        cout << g << " ";
    cout << endl; */

    int crr[size_arr + size_brr + 2];

    int ia = 0, ib = 0;

    int start = 0;

    while(ia<size_arr && ib<size_brr)
    {
        if(arr[ia]<brr[ib])
        {
            crr[start] = arr[ia];
            ia++;
            start++;
        }
        else if(arr[ia]>brr[ib])
        {
            crr[start] = brr[ib];
            ib++;
            start++;
        }
        else
        {
            crr[start] = arr[ia];
            ia++;
            start++;
        }
    }

    for (int i = ia; i < size_arr;i++)
    {
        crr[start] = arr[i];
        start++;
    }

    for (int i = ib; i < size_brr; i++)
    {
        crr[start] = brr[i];
        start++;
    }

    /* for (int i = 0; i < size_arr + size_brr;i++)
        cout << crr[i] << " ";
    cout << endl; */

    int sum = 0;
    int len = size_arr + size_brr;
    for (int i = 0; i <len ; i++)
    {
        cin >> arr[i];
        sum = sum + crr[i];
    }

    double mean = (sum * 1.0) / len;
    double median;

    int mid = (len / 2) - 1;

    if (len % 2 == 0)
    {
        median = ((arr[mid] + arr[mid + 1]) * 1.0) / 2;
    }
    else
    {
        median = arr[mid + 1];
    }

    cout << "Mean " << mean << " Median " << median << endl;
}
