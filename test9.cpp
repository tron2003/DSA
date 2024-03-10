#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int func (int arr[],int n){

     int res =1;
     int curr=1;

     for(int i=1;i<n;i++){
        if((arr[i]%2==0 &&arr[i-1]%2!=0)||(arr[i]%2!=0 &&arr[i-1]%2==0)){

            curr++;
            res = max(curr,res);
        }
        else{
            curr=1;
        }
     }
     


    return res;


}
int main(){
   
int arr[]={5,10,20,6,3,8};
cout<<func(arr,6);

return 0 ;
}