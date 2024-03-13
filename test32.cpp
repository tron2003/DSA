#include<iostream>
#include<bits/stdc++.h>
using namespace std;


void func(int arr[],int n){
int i =-1;
int j =n;
while(true){

    do{i++;}while(arr[i]<0);
    do{j--;}while(arr[j]>0);
    if(i>=j){
        return ;
    }
    swap(arr[i],arr[j]);
}


}

int main(){
   int arr[] = {7,-3,1,-8,9,-12,-56};
   func(arr,7);
   for(auto x:arr){
    cout<<x<<" ";
   }

return 0 ;
}