class Solution {

    int helper(vector<int>& arr, int l, int h) {

        while (l <h) {
            int mid = l + (h - l) / 2;

            if (arr[mid] < arr[mid + 1]) {

                l = mid + 1;
            } else {

                h = mid;
            }
           
        }
        return l;
    }

public:
    int findPeakElement(vector<int>& arr) { return helper(arr, 0, arr.size()-1); }
};