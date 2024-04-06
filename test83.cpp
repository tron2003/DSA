#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void rec(int n)
{
    queue<string> que;
    que.push("5");
    que.push("6");
    for (int i = 0; i < n; i++)
    {

        string x = que.front();
        cout << x << " ";
        que.pop();
        que.push(x + "5");
        que.push(x + "6");
    }
}

int main()
{
    // queue<int> que;
    // int n;
    // cin >> n;
    // for (int i = 0; i < n; i++)
    // {
    //     int x;
    //     cin >> x;
    //     que.push(x);
    // }
    rec(100);
    // while(!que.empty()){
    //     cout<<que.front()<<"  " ;
    //     que.pop();
    // }
    return 0;
}