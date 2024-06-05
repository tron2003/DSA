#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int helper(vector<int> arr, int n, int i, int a)
{

    if(a==0){
        return 0;
    }
    if(a<0){
        return INT_MAX;
    }

    int ans = INT_MAX;
    for (int j = 0;j<n;j++){

        int temp = helper(arr, n, i, a - arr[j]);
        if(temp!=INT_MAX){

        ans = min(ans, 1 +temp);
        }
    }
    return ans;
}

void func()
{
    vector<int> arr = {1, 2, 5};
    int n = arr.size();
    int res = 0;
    int a = 11;
    int i = 0;
    res = helper(arr, n, i, a);
    cout << res;
}

int main()
{
    func();
    return 0;
}