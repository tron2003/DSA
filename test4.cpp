#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int func(int arr[], int n)
{   int lmax[n];
    int rmax[n];
    int res=0;
    lmax[0]=arr[0];
    for(int i =1;i<n;i++){

        lmax[i]=max(lmax[i-1],arr[i]);
    }
     rmax[n-1] = arr[n-1];

     for(int i =n-2;i>=0;i--){

        rmax[i]= max(arr[i],rmax[i+1]);
     }
    for(int i =1;i<n-1;i++){
   res+=(min(lmax[i],rmax[i]))-arr[i];

    }
    return res;
}

int main()
{

    int arr[] = {2};

    cout << func(arr, 5);

    return 0;
}