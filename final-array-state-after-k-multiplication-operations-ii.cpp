class Solution
{
    int M = 1e9 + 7;
    int Modpower(long base, int exp)
    {
        long res = 1;
        while (exp)
        {
            if (exp & 1)
            {
                res = (res * base) % M;
            }
            base = (base * base) % M;
            exp = exp >> 1;
        }

        return res;
    }

public:
    vector<int> getFinalState(vector<int> &nums, int k, int mul)
    {
        if (mul == 1)
            return nums;

        const long maxElem = *max_element(nums.begin(), nums.end());
        int n = nums.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        for (int i = 0; i < n; i++)
            pq.push({nums[i], i});

        while (k && (1LL * pq.top().first * mul <= maxElem))
        {
            auto [val, index] = pq.top();
            pq.pop();

            val = (1LL * val * mul) % M;
            pq.push({val, index});
            k--;
        }

        .const long power = k / n;

        int newMul = Modpower(mul, power);

        // Now multiply every term with 'newMul'.
        while (!pq.empty())
        {
            auto [val, index] = pq.top();
            pq.pop();

            // First few terms will be additionally multiplied by 'mul'
            // as some remaining multiplications can't be equally divided
            // amongst all the terms.
            if (k % n)
            {
                k--;
                nums[index] = ((1LL * newMul * mul) % M * val) % M;
            }
            else
            {
                nums[index] = (1LL * val * newMul) % M;
            }
        }

        return nums;
    }
};