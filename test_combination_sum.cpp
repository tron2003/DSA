#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int helper(vector<int>arr,int t,int n )

{     
    if(t==0){
        return 1;
    }
    if(t<0){
        return 0;
    }

    int inc = 0;
    int exe = 0;
    for (int i = 0; i < n;i++){
        inc += helper(arr, t - arr[i], n);
    }
    return inc;
}

void func()
{
    vector<int> arr = {1,2,5};
    int t = 5;
    int n = 3;

    

    int res = helper(arr,t,n);
    cout << res;
}

int main()
{
    func();
    return 0;
}