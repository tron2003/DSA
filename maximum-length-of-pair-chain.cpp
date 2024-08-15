class Solution
{
public:
    int findLongestChain(vector<vector<int>> &arr)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            que;

        for (auto x : arr)
        {

            que.push({x[1], x[0]});
        }
        int res = 1;
        int free = que.top().first;
        que.pop();
        while (!que.empty())
        {
            auto x = que.top();
            que.pop();
            if (x.second > free)
            {

                free = x.first;
                res++;
            }
        }

        return res;
    }
};