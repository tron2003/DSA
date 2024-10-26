class Solution
{
public:
    void rec(int level, int &cnt, unordered_map<char, int> &mpp, int n)
    {
        // base case
        cnt++;
        if (level == n)
        {
            return;
        }
        // recursive case
        for (auto v : mpp)
        { // choice
            // take
            if (v.second != 0)
            { // check
                mpp[v.first]--;
                rec(level + 1, cnt, mpp, n);
                mpp[v.first]++;
            }
        }
    }
    int numTilePossibilities(string tiles)
    {
        int cnt = 0;
        unordered_map<char, int> mpp;
        int n = tiles.size();

        for (int i = 0; i < n; i++)
            mpp[tiles[i]]++;

        rec(0, cnt, mpp, n);

        return cnt - 1;
    }
};