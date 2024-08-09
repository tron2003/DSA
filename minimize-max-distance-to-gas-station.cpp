//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    double findSmallestMaxDist(vector<int> &arr, int k)
    {
        // Code here
        int n = arr.size();
        vector<int> how(n - 1, 0);
        priority_queue<pair<long double, int>> que;
        for (int i = 0; i < n - 1; i++)
        {
            que.push({arr[i + 1] - arr[i], i});
        }
        for (int i = 0; i < k; i++)
        {
            auto top = que.top();
            que.pop();
            int secidx = top.second;
            how[secidx]++;
            long double indiff = arr[secidx + 1] - arr[secidx];
            long double newsection = indiff / (long double)(how[secidx] + 1);
            que.push({newsection, secidx});
        }
        return que.top().first;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> stations(n);
        for (int i = 0; i < n; i++)
        {
            cin >> stations[i];
        }
        int k;
        cin >> k;
        Solution obj;
        cout << fixed << setprecision(2) << obj.findSmallestMaxDist(stations, k)
             << endl;
    }
    return 0;
}
// } Driver Code Ends