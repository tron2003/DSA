#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> func(int arr[], int n)
{
    stack<int>st;
    st.push(0);
    vector<int>res;
    res.push_back(1);
    for(int i =1;i<n;i++){

        while(!st.empty() && arr[st.top()]<=arr[i]){

            st.pop();
        }
        int span = st.empty() ?i+1:i-st.top();
        res.push_back(span);
        st.push(i);
    }
    return res;
}

int main()
{

    int arr[] = {10, 20, 30, 40};
    vector<int> str = func(arr, 4);
     for(auto x:str){
        cout<<x<<' ';
     }
    return 0;
}