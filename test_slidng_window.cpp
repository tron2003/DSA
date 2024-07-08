#include <bits/stdc++.h>
#include<iostream>
using namespace std;

int helper(vector<int> arr, int n, int l, int r, int k)
{
    int sum = 0;
    int maxlength = 0;
    while (r < n)
    {

        sum += arr[r];
       if(sum > k &&l<=r)
        {
            sum -= arr[l];
            l++;
        }
        if (sum <= k)
        {

            maxlength = max(maxlength, r- l + 1);
        }
        r++;
    }
    return maxlength;
}

void man()
{
    vector<int> arr = {1, 4, 4, 423};
    int n = arr.size();
    int k = 0;
    int res = helper(arr, n, 0, 0, k);
    cout << res;

}

int main()
{
    man();
    return 0;
}