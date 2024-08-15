class Solution
{
public:
    string getPermutation(int n, int k)
    {
        int fact = 1;
        vector<int> temp;
        for (int i = 1; i < n; i++)
        {
            fact = fact * i;
            temp.push_back(i);
        }
        temp.push_back(n);
        string res = "";
        k = k - 1;
        while (true)
        {
            res = res + to_string(temp[k / fact]);
            temp.erase(temp.begin() + k / fact);
            if (temp.size() == 0)
            {
                break;
            }
            k = k % fact;
            fact = fact / temp.size();
        }
        return res;
    }
};