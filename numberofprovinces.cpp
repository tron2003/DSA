#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

class Solution
{
public:
    void dfs(unordered_map<int, list<int>> &mp, vector<bool> &vis, int i)
    {
        vis[i] = true;
        for (auto n : mp[i])
        {
            if (!vis[n])
            {
                dfs(mp, vis, n);
            }
        }
    }

    int findCircleNum(vector<vector<int>> &arr)
    {
        unordered_map<int, list<int>> mp;
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (arr[i][j] == 1 && i != j)
                {
                    mp[i + 1].push_back(j + 1);
                    mp[j + 1].push_back(i + 1);
                }
            }
        }
        int res = 0;
        vector<bool> vis(n + 1, false);
        for (int i = 1; i <= n; i++)
        {
            if (!vis[i])
            {
                res++;
                dfs(mp, vis, i);
            }
        }
        return res;
    }
};

// Test cases
int main()
{
    Solution sol;
    vector<vector<int>> test1 = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
    vector<vector<int>> test2 = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    vector<vector<int>> test3 = {{1, 1, 0, 0}, {1, 1, 0, 0}, {0, 0, 1, 1}, {0, 0, 1, 1}};

    cout << "Test Case 1: " << sol.findCircleNum(test1) << " (Expected: 2)" << endl;
    cout << "Test Case 2: " << sol.findCircleNum(test2) << " (Expected: 3)" << endl;
    cout << "Test Case 3: " << sol.findCircleNum(test3) << " (Expected: 2)" << endl;

    return 0;
}
