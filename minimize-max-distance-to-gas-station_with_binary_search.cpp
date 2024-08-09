//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int helper(vector<int> &arr, double mid)
    {
        int cnt = 0;
        for (int i = 1; i < arr.size(); i++)
        {
            int diff = arr[i] - arr[i - 1];
            cnt += (int)(diff / mid); // Possible cause of Floating-point exception
        }
        return cnt;
    }

    double findSmallestMaxDist(vector<int> &arr, int k)
    {
        // Code here

        int n = arr.size();
        double low = 1e-9;
        double high = 0;
        for (int i = 0; i < n - 1; i++)
        {

            high = max(high, (double)(arr[i + 1] - arr[i]));
        }
        double diff = 1e-6;
        while (high - low > diff)
        {

            double mid = (double)(low + high) / (2);
            int cnt = helper(arr, mid);
            if (cnt <= k)
            {
                high = mid;
            }
            else
            {
                low = mid;
            }
        }
        return high;
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