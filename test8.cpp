#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int func(int arr[], int n)
{   int res=arr[0];
  int temp =arr[0];
  for(int i=1;i<n;i++){

    temp = max(temp+arr[i],arr[i]);
    res = max(temp,arr[i]);
  }
    return res;
}
int main(){
   int arr[]={5,8,3};
   cout<<(func(arr,3));
return 0 ;
}