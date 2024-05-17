#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int func(vector<int>d,vector<int>p,int n){
    vector<pair<int, int>> temp;
    int res = 0;
    for (int i = 0; i < n;i++){
        temp.push_back({p[i],d[i]});
    }
    sort(temp.begin(), temp.end(), [](const pair<int, int> &a, const pair<int, int> &b)
         { return a.first > b.first; });
    vector<int> slot(n, -1);
    for (int i = 0; i < n;i++){

        for (int j = min(n, temp[i].second - 1); j >= 0;j--){

            if(slot[j]==-1){
                slot[j] = i;
                res += temp[i].first;
                break;
            }
        }
    }

        return res;
}

int main(){
    // vector<pair<int,int>>arr={}
    vector<int> p = {70, 80, 30, 100};
    vector<int> d = {4, 1, 1, 1};
    cout << func(d, p, 4);

    return 0;
}