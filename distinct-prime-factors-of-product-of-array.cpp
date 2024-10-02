class Solution
{
public:
    void helper(set<int> &st, int x)
    {

        long long div = 2;

        while (x > 1)
        {

            if (x % div == 0)
            {

                st.insert(div);

                x = x / div;
            }
            else
            {
                div++;
            }
        }
    }
    int distinctPrimeFactors(vector<int> &arr)
    {
        set<int> st;
        for (auto x : arr)
        {

            helper(st, x);
        }
        return st.size();
    }
};