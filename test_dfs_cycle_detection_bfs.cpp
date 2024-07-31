#include <bits/stdc++.h>
// bool helper(int node, unordered_map<int, list<int>> &arr,
//             unordered_map<int, bool> &mp) {
//   unordered_map<int, int> parent;

//   mp[node] = 1;
//   parent[node] = -1;
//   queue<int> que;
//   que.push(node);
//   while (!que.empty()) {

//     int temp = que.front();
//     que.pop();
//     for (auto x : arr[temp]) {

//       if (mp[x] == 1 && x != parent[temp]) {
//         return true;

//       } else if (!mp[x]) {
//         que.push(x);
//         mp[x] = 1;
//         parent[x] = temp;
//       }
//     }
//   }
//   return false;
// }
bool helper(int node, int parent, unordered_map<int, list<int>> &arr,
            unordered_map<int, bool> &mp)
{

    mp[node] = 1;

    for (auto x : arr[node])
    {

        if (!mp[x])
        {

            if (helper(x, node, arr, mp) == 1)
            {
                return true;
            }
        }
        else if (x != parent)
        {
            return true;
        }
    }

    return false;
}
string cycleDetection(vector<vector<int>> &ed, int n, int m)
{

    unordered_map<int, bool> mp;
    unordered_map<int, list<int>> arr;
    for (int i = 0; i < m; i++)
    {

        int i1 = ed[i][0];
        int i2 = ed[i][1];
        arr[i1].push_back(i2);
        arr[i2].push_back(i1);
    }
    for (int i = 0; i < n; i++)
    {

        if (mp[i] == 0)
        {

            if (helper(i, -1, arr, mp) == 1)
            {
                return "Yes";
            }
        }
    }
    return "No";
    // Write your code here.
}
