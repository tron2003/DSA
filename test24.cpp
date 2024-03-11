#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool func(int arr[], int n, int x, int si) {
    int i = si;
    int j = n - 1;
    while (i < j) {
        if (arr[i] + arr[j] == x) {
            return true;
        }
        if (arr[i] + arr[j] < x) {
            i++;
        } else {
            j--; // Decrement j when the sum is greater than x
        }
    }
    return false;
}


bool func2(int arr[], int n, int x) {
    for (int i = 0; i < n - 2  ; i++) { // Changed n - 2 to n - 1
        if (func(arr, n, x - arr[i], i + 1)) {
            return true;
        }
    }
    return false;
}

int main() {
    int arr[] = {5, 10, 20, 100, 7};
    cout << func2(arr, 5, 35);
    return 0;
}
