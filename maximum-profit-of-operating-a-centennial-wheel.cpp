class Solution
{
public:
    int helper(int &wait, int cost, int run)
    {

        int k = min(4, wait);
        wait = wait - k;

        return k * cost - run;
    }
    int minOperationsMaxProfit(vector<int> &arr, int cost, int run)
    {
        int maxpro = 0;
        int profit = 0;
        int maxrot = 0;
        int rot = 0;
        int wait = 0;
        int n = arr.size();
        for (int i = 0; i < n || wait > 0; i++)
        {

            if (i < n)
            {
                wait += arr[i];
            }
            profit += helper(wait, cost, run);
            rot++;
            if (profit > maxpro)
            {
                maxpro = profit;
                maxrot = rot;
            }
        }

        return maxpro > 0 ? maxrot : -1;
    }
};