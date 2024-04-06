#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void rec(queue<int> &que)
{

    if (que.empty())
    {
        return;
    }
    int x = que.front();
    que.pop();
    rec(que);
    que.push(x);
}

int main()
{
    queue<int> que;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        que.push(x);
    }
    rec(que);
    while(!que.empty()){
        cout<<que.front()<<"  " ;
        que.pop();
    }
    return 0;
}