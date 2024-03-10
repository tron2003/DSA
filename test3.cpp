#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void func(string arr, int n = 0) {
    if (n == arr.length() - 1) {
        cout << arr << endl;
        return;
    }

    for (int i = n; i < arr.length(); i++) {
        swap(arr[n], arr[i]);
        func(arr, n + 1);
        swap(arr[i], arr[n]); // Backtrack to original arrangement
    }
}

int main() {
    string arr = "sabsa";
    func(arr);
    return 0;
}
