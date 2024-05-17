#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int func(vector<int> arr, int n, int amount)
{

    int res = 0;
    
    sort(arr.begin(), arr.end(),greater<int>());
    for (int i = 0; i < n; i++)
    {
        cout << i <<" "<< "Iteration" << endl;
        if (arr[i] <= amount)
        {

            int c = amount / arr[i];
            res += c;
            amount -= (c * arr[i]);
        }
        if(amount==0){
            break;
        }
    }
    return res;
}

int main()
{
    vector<int> arr = {18,1, };
    cout << func(arr, 3, 20);

    return 0;
}