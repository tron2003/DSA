#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int longestIncreasingSubsequence(vector<int> &arr)
{
    vector<int> dp; // dp array to store the end elements of each length
    // sort(arr.begin(), arr.end());
    for (int num : arr)
    {
        auto it = lower_bound(dp.begin(), dp.end(), num);
        if (it == dp.end())
        {
            dp.push_back(num); // num is greater than any element in dp
        }
        else
        {
            *it = num; // replace the first element in dp which is >= num
        }
    }
    return dp.size();
}

int main()
{
    vector<int> arr = {3, 4, 2, 8, 10};
    cout << "Length of longest increasing subsequence is " << longestIncreasingSubsequence(arr) << endl;
    return 0;
}
