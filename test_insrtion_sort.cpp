#include <iostream>
#include <vector>

using namespace std;

void helper(vector<int> &arr, int n)
{

    for (int i = 1; i < n ; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        for (; j >= 0;j--){
            
            if(arr[j]>temp){

                arr[j + 1] = arr[j];
            }
            else{
                break;
            }



        }
        arr[j + 1] = temp;
    }
}

int main()
{

    vector<int> arr = {10, 7, 6, 5, 10};

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
