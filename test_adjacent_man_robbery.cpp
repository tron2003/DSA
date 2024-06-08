#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int helper(vector<int> arr, vector<int> dp, int n)
{

    int temp1 = 0;
    int temp2 = arr[0];
    for (int i = 1; i < n; i++)
    {

        int inc = temp1 + arr[i];
        int exe = temp2 + 0;
        int ans = max(inc, exe);
        temp1 = temp2;
        temp2 = ans;
    }
    return temp2;
}

void func()
{
    vector<int> arr = {3, 2, 7, 10};
    int n = arr.size();
    int res = 0;

    int i = 0;
    vector<int> dp(n, 0);
    vector<int> arr1;
    vector<int> arr2;

    for (int i = 0; i < n;i++){
       if(i!=0){
           arr1.push_back(arr[i]);
       }
       if(i!=n-1){
           arr2.push_back(arr[i]);
       }

    }

        res = max(helper(arr1, dp, n),helper(arr2,dp,n));
    cout << res;
}

int main()
{
    func();
    return 0;
}