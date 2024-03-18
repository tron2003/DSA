#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void func(int arr[],int n,int k){
  int count[k];
  for(int i =0;i<k;i++){
    count[i]=0;
  }
  for(int i =0;i<n;i++){

    count[arr[i]]++;
  }

  for(int i=1;i<n;i++){
    count[i]=count[i-1]+count[i];
  }
  int temp[n];
  for(int i=n-1;i>=0;i--){

    temp[count[arr[i]]-1]=arr[i];
    count[arr[i]]--;

  }
  for(int i =0;i<n;i++){

    arr[i]=temp[i];
  }


}

int main(){
   int arr[] = {1,4,4,1,0,1};
    func(arr, 6,5);
    for (auto x : arr)
    {
        cout << x << " ";
    }
return 0 ;
}