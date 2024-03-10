#include<iostream>
#include<bits/stdc++.h>
using namespace std;
inline vector<int> func1(int arr[],int n){
   vector<int>res(n,0);
   res[0]=arr[0];
   for(int i =1;i<n;i++){
    res[i]= (arr[i]+res[i-1]);
   }
    return res;
}

int func2(int arr[],int n,int l,int r){
   vector<int>res(n,0);
   res = func1(arr,n);
    if(l==0){
         return res[r];}
    return res[r]-res[l-1];

}


int main(){
     
  int arr[] = {2,8,3,9,6,5,4};
    cout << func2(arr, sizeof(arr) / sizeof(arr[0]),0,1); 

return 0 ;
}