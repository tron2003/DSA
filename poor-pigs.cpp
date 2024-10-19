class Solution
{
public:
    int poorPigs(int buckets, int end, int test)
    {
        return ceil(log2(buckets) / log2(int(test / end) + 1));
    }
};