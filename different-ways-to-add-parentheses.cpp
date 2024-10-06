class Solution
{
public:
    vector<int> diffWaysToCompute(string s)
    {
        vector<int> res;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {

            char temp = s[i];
            if (temp == '-' || temp == '+' || temp == '*')
            {
                vector<int> left = diffWaysToCompute(s.substr(0, i));
                vector<int> right = diffWaysToCompute(s.substr(i + 1));
                for (auto m : left)
                {
                    for (auto n : right)
                    {

                        if (temp == '-')
                        {

                            res.push_back(m - n);
                        }
                        else if (temp == '+')
                        {
                            res.push_back(m + n);
                        }
                        else
                        {
                            res.push_back(m * n);
                        }
                    }
                }
            }
        }
        if (res.empty())
        {
            res.push_back(stoi(s));
        }
        return res;
    }
};