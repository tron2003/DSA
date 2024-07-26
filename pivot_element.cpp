class Solution {
public:
    int helper(vector<int>& arr) {
        int l = 0;
        int h = arr.size() - 1;

        while (l < h) {
            int mid = l + (h - l) / 2;
            if (arr[h] <=arr[mid]) {
                l = mid + 1;
            } else {

                h = mid;
            }
        }
        return arr[l];
    }
    int findMin(vector<int>& nums) {
        int res = helper(nums);
        return res;
    }
};