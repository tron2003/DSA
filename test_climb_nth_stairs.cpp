#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void helper(int i,int n,int &res){
    if(i==n){
        res++;
        return;
    }
    if(i>n){
        return;
    }

     helper(i+1,n,res);
     helper(i + 2, n, res);
     // return 
}
void func(int n){

    if(n==0){
        return;
    }
    int res=0;
    int i =0;
    helper(i,n, res);
    cout << res;
    // return ;
}

int main(){
    func(3);

    return 0;
}