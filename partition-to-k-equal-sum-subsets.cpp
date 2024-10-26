class Solution
{
public:
    bool helper(int i, int sum, int tar, int k, vector<int> &arr,

                vector<int> &visit)
    {

        if (k == 0)
        {
            return 1;
        }
        if (sum > tar)
        {

            return false;
        }
        if (sum == tar)
        {
            return helper(0, 0, tar, k - 1, arr, visit);
        }
        if (i >= arr.size())
        {
            return false;
        }

        for (int j = i; j < arr.size(); j++)
        {

            if (visit[j] == 1)
            {

                continue;
            }
            visit[j] = 1;

            if (helper(j + 1, sum + arr[j], tar, k, arr, visit))
            {

                return true;
            }
            visit[j] = 0;
            if (sum == 0)
            {
                break;
            }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int> &arr, int k)
    {

        int sum = accumulate(arr.begin(), arr.end(), 0);

        int tar = sum / k;
        if (sum % k != 0 || arr.size() < k)
        {

            return 0;
        }

        vector<int> visit(arr.size() + 1, 0);
        return helper(0, 0, tar, k, arr, visit);
    }
};