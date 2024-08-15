#define p pair<int, int>
class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &arr)
    {
        int n = arr.size();
        priority_queue<p, vector<p>, greater<p>> que;
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
            if (x.second >= free)
            {

                res++;
                free = x.first;
            }
        }
        return n - res;
    }
};