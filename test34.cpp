#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int mycamp (pair<int,int>&a,pair<int,int>&b){
    return a.first <b.first;
}
void func(vector<pair<int,int>> arr, int n)
{
    sort(arr.begin(),arr.end(),mycamp);
    vector<pair<int,int>> merged;
    merged.push_back(arr[0]);
    
    for(int i = 1; i < n; i++) {
        if(merged.back().second >= arr[i].first) {
            merged.back().first = min(merged.back().first, arr[i].first);
            merged.back().second = max(merged.back().second, arr[i].second);
        }
        else {
            merged.push_back(arr[i]);
        }
    }

    for(int i = 0; i < merged.size(); i++) {
        cout << merged[i].first << " " << merged[i].second << endl;
    }
}




int main()
{
    vector<pair<int,int>>arr={{1,3},{2,4},{5,7},{6,8}};
    

    func(arr, sizeof(arr)/sizeof(arr[0]));
    // for (auto x : arr)
    // {
    //     cout << x << " ";
    // }

    return 0;
}