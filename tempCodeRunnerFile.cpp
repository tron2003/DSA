#include <bits/stdc++.h>
using namespace std;

int helper(vector<int> arr, int n, int l, int r, int k)
{
    int sum = 0;
    int maxlength = 0;
    while (r < n)
    {

        sum += arr[r];
        while (sum > k)
        {
            sum -= arr[l];
            l = l + 1;
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
    int k = 2;
    int res = helper(arr, n, 0, 0, k);
    cout << res;
}

int main()
{
    man();
    return 0;
}