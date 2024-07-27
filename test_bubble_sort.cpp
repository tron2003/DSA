#include<iostream>
#include<vector>

using namespace std;
 
void helper(vector<int>&arr,int n){

    for (int i = 0; i < n - 1;i++){
        bool swapy = false;
        for (int j = 0; j < n -i-1;j++){

            if(arr[j]>arr[j+1]){
                swap(arr[j], arr[j + 1]);
                swapy = true;
            }
        }
        if(swapy ==false){
            break;
        }
    }
}

int main(){

    vector<int> arr = {10,7,6,5,10};

    cout << "Before Sorting" << endl;
    for (auto x : arr)
    {

        cout << x << " ";
    }
    cout << endl;
    helper(arr, arr.size());
    cout << "After Sorting" << endl;
    for (auto x : arr)
    {

        cout << x << " ";
    }
    return 0;
}
