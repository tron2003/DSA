#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void func(vector<int>res,int n ){
    int res1 = 0;
    for(auto x:res){
        res1 ^= x;
    }
    int res2 = res1 & ~(res1 - 1);
    int res3 = 0;
    int res4 = 0;
    for (int i = 0; i < n;i++){

        if((res[i] &(res2))!=0){
            res3 ^= res[i];
        }
        else{
            res4 ^= res[i];
        }
    }
    cout << res3 << " " << res4 << endl;
}


int main(){
    func({3, 4, 3, 4, 5, 4, 4, 6, 7, 7}, 10);
    return 0;
}