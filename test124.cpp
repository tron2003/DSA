#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class triplet
{
public:
    int val, x, y;
    triplet(int val1, int val2, int val3)
    {
        val = val1;
        x = val2;
        y = val3;
    }
};

class mycmp
{
public:
    bool operator()(triplet &t1, triplet &t2)
    {
        return t1.val > t2.val;
    }
};

vector<int> merge(vector<vector<int>> &arr)
{
    vector<int> res;
    auto cmp=[](triplet &t1, triplet &t2) 
                   {
        return t1.val > t2.val;
                   };
    priority_queue<triplet, vector<triplet>, decltype(cmp)>
        que(cmp);
    for (int i = 0; i < arr.size(); i++)
    {

        triplet t(arr[i][0], i, 0);
        que.push(t);
    }
    while (que.empty() == false)
    {
        triplet curr = que.top();
        que.pop();
        res.push_back(curr.val);
        int ap = curr.x;
        int vp = curr.y;
        if (vp + 1 < arr[ap].size())
        {
            triplet t = {arr[ap][vp + 1], ap, vp + 1};
            que.push(t);
        }
    }
    return res;
}
int main()
{
    vector<vector<int>> arr = {{1, 3, 5, 7},
                               {2, 4, 6, 8},
                               {0, 9, 10, 11}};
    vector<int> merged = merge(arr);

    cout << "Merged sorted array: ";
    for (int num : merged)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
