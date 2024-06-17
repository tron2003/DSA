#include <iostream>

#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

void func()
{
    vector<int> arr = {7, 5, 1, 3, 6, 4};
    int min1 = arr[0];
    int res = INT_MIN;
    int n = arr.size();
    for (int i = 1; i < n;i++){
        int temp = arr[i] - min1;
        res = max(res, temp);
        min1 = min(arr[i], min1);
    }
    cout << res;
}

int main()
{
    func();
    return 0;
}
