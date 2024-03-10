#include <iostream>
using namespace std;

int func1(int arr[], int n) {
    int res =arr[0];
    int count=1;

    for(int i =1;i<n;i++){

        if(arr[i]==res){
            count++;
        }
        else{
            count--;
            if(count==0){
                res=arr[i];
                count=1;
            }
        }
    }
    count=0;

    for(int i =0;i<n;i++){

        if(res==arr[i]){
            count++;
        }
    }
    if (count > n / 2) {
        return res;
    } else {
        return -1;
    }
}

int main() {
    int arr[] = {7,7,7,8,8,5};
    cout << func1(arr, 6) << " ";
    return 0;
}
