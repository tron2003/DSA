#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int quick(vector<int> &arr, int low,  int high)
{

    int p = arr[low];
    int i = low;
    int j = high;
    while(i<j){

        while(i<high&&arr[i]<=p){

            i++;
        }
        while(j>=low+1 &&arr[j]>p){
            j--;
        }
        if(i<j){
            swap(arr[i], arr[j]);
            // swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[j]);
    return j++;
}

void quicksort(vector<int> &arr, int low, int high)
{

    if (low < high)
    {

        
        int p =quick(arr, low, high);
        quicksort(arr, low, p-1);
        quicksort(arr, p+1,high);
    }
}

int main()
{

    vector<int> arr = {5, 3, 4, 2, 6, 7};
    int n = arr.size();
    for (auto x : arr)
    {

        cout << x << "  ";
    }
    cout << endl;
    quicksort(arr, 0, n - 1);
    for (auto x : arr)
    {

        cout << x << "  ";
    }

    return 0;
}
