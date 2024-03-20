#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

void func(int arr[], int n=6,int k =4)
{
    unordered_map<int,int> mp;
    for (size_t i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }
    
    for(auto x:mp){

        if(x.second>(n/k)){
            cout<<x.first<<" "<<x.second<<endl;

        }
    }
      
}

int main()
{
    int arr[] = {30,10,20,20,10,20,30,30};
    int arr2[] = {1, 0, 1, 0, 0, 1};
    func(arr, sizeof(arr)/sizeof(arr[0]));

    return 0;
}
