class Solution
{
public:
    vector<long long> maximumEvenSplit(long long sum)
    {

        if (sum % 2 != 0)
            return {};

        vector<long long> ans;
        long long current = 2;

        while (sum >= current)
        {
            ans.push_back(current);
            sum -= current;
            current += 2;
        }

        if (sum > 0)
        {
            ans.back() += sum;
        }

        return ans;
    }
};
