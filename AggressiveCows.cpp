#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int ischeck(vector<int> &arr, int n, int k, int mid)
{
    int count = 1;     // We place the first cow in the first stall
    int last = arr[0]; // Position of the last placed cow

    for (int i = 1; i < n; i++)
    { // Start from the second stall
        if (arr[i] - last >= mid)
        {            // Check if the current stall is at least 'mid' distance away from the last cow
            count++; // Place a cow here
            if (count == k)
            {                // If all cows are placed
                return true; // Return true
            }
            last = arr[i]; // Update the position of the last placed cow
        }
    }
    return false; // Return false if not all cows could be placed with at least 'mid' distance
}

int aggressiveCows(vector<int> &arr, int k)
{
    sort(arr.begin(), arr.end()); // Sort the stall positions
    int n = arr.size();
    if (k > n)
    { // If there are more cows than stalls, it's not possible to place them
        return -1;
    }

    int l = 0;
    int h = arr[n - 1] - arr[0]; // Maximum possible distance
    int res = -1;                // Initialize result

    while (l <= h)
    {
        int mid = l + (h - l) / 2; // Find the middle distance
        if (ischeck(arr, n, k, mid))
        {                // Check if it's possible to place all cows with at least 'mid' distance
            res = mid;   // Update result
            l = mid + 1; // Try for a larger distance
        }
        else
        {
            h = mid - 1; // Try for a smaller distance
        }
    }
    return res; // Return the largest minimum distance
}

int main()
{
    vector<int> stalls = {1, 2, 4, 8, 9}; // Example stall positions
    int cows = 3;                         // Number of cows
    cout << "Largest minimum distance: " << aggressiveCows(stalls, cows) << endl;
    return 0;
}
