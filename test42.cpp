#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool func(int arr[],int n,int sum){
  

  unordered_set<int>mp;
  int pre_sum =0;;
  for(int i =0;i<n;i++){

    pre_sum +=arr[i];
    if(mp.find(pre_sum-sum)!=mp.end()){

        return true;
    }
    if(pre_sum==sum){
        return true;
    }
    else{

        mp.insert(pre_sum);
    }
  }
return false;

}

int main(){

    int arr[]={12,2334,34123,-9000,1,100,45};
    cout<<func(arr,7,145);
   
return 0 ;
}