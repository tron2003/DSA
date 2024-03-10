#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int func(int arr[],int n ,int k){

   int low =0;
   int high = n-1;
   while(low<=high){

    int mid=low +(high-low)/2;
    if(arr[mid]==k){

        return mid;
    }
    else if(arr[mid]>k){
        high = mid-1;
    }
    else{
        low = mid+1;
    }
   }
   return -1;
}


int main(){
   int arr[] = {0,1, 2, 3,4,5};
    cout << func(arr, sizeof(arr) / sizeof(arr[0]),3);
return 0 ;
}