#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int func1(int arr[], int n, int sum)
{

    int s = 0;
    int curr = 0;
    for (int i = 0; i <= n; i++)
    {
      while(curr>sum &&s<i){
        curr= curr-arr[s];
        s++;
      }
       if(sum==curr){
        return true;
       } 
       if(i<n){
        curr +=arr[i];
       }
    }
    return false;
}

int main()
{
    int arr[] = {4, 8, 12, 5};
    cout << func1(arr, sizeof(arr) / sizeof(arr[0]), 12);
    return 0;
}
