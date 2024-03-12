#include <iostream>
#include <bits/stdc++.h>
using namespace std;

double func(int arr1[], int arr2[], int n1, int n2)
{
    int b1 = 0;
    int e1 = n1;

    while (b1 <= e1)
    {
        int i1 = (b1 + e1) / 2;
        int i2 = (n1 + n2 + 1) / 2 - i1;

        int ml1 = (i1 == 0) ? INT_MIN : arr1[i1 - 1];
        int mr1 = (i1 == n1) ? INT_MAX : arr1[i1];
        int ml2 = (i2 == 0) ? INT_MIN : arr2[i2 - 1];
        int mr2 = (i2 == n2) ? INT_MAX : arr2[i2];

        if (ml1 <= mr2 && ml2 <= mr1)
        {
            if ((n1 + n2) % 2 == 0)
                return (max(ml1, ml2) + min(mr1, mr2)) / 2.0;
            else
                return max(ml1, ml2);
        }
        else if (ml1 > mr2)
        {
            e1 = i1 - 1;
        }
        else
        {
            b1 = i1 + 1;
        }
    }
    return -1; // If input arrays are not sorted or have invalid sizes
}

int main()
{
    int arr1[] = {10, 20, 20, 40, 50};
    int arr2[] = {5, 15, 25, 35, 45};
    cout << func(arr1, arr2, 5, 5);

    return 0;
}
