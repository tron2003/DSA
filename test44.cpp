#include <iostream>
#include <unordered_map>
using namespace std;

int func(int arr1[],int arr2[],int n)
{   int temp[n];
    for (int i = 0; i < n; i++)
    {
        temp[i]=arr1[i]-arr2[i];
    }
    unordered_map<int, int> mp;
    int pre_sum = 0;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        pre_sum += temp[i];
        if (pre_sum == 0)
        {
            // If sum is found at the beginning of the array
            res= i + 1;
        }
        if (mp.find(pre_sum) == mp.end())
        {
            mp.insert({pre_sum, i});
        }
        if (mp.find(pre_sum) != mp.end())
        {
            res = max(res, i - mp[pre_sum]);
        }
    }
    return res;
}

int main()
{
    int arr[] = {0,1,0,0,0,0};
    int arr2[] ={1,0,1,0,0,1};
    cout << func(arr,arr2, 6);

    return 0;
}
