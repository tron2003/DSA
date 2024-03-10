#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void func(string str, int a = 3)

{
    // int arr[256];
    int powe = pow(2, a);

    for (int i = 0; i < powe; i++)
    {

        for (int j = 0; j < a; j++)
        {

            if ((i & (1 << j)) != 0)
            {
                cout << str[j];
            }
        }
        cout<<endl;
    }
}

int main()
{

    string arr = "abc";
    func(arr);

    return 0;
}
