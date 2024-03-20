#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int func(int arr[], int n = 6)
{
    unordered_set<int> mp(arr, arr + n);
    int res=1;
    for(int i=0;i<n;i++){

        if(mp.find(arr[i]-1)==mp.end()){

            int ces = 1;
            while(mp.find(arr[i]+ces)!=mp.end()){

                ces++;
            }
            res= max(res,ces);
        }
    }
    return res;
}

int main()
{
    int arr[] = {0, 1, 2, 3, 0, 0};
    int arr2[] = {1, 0, 1, 0, 0, 1};
    cout << func(arr, 6);

    return 0;
}
