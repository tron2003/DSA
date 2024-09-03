class Solution
{
public:
    static bool cmp(pair<long long, long long> &a,
                    pair<long long, long long> &b)
    {

        double x = double(a.first) / (double)a.second;
        double y = double(b.first) / (double)b.second;
        return x > y;
    }
    long long minDamage(int power, vector<int> &arr1, vector<int> &arr2)
    {
        int n = arr1.size();
        int sum = 0;
        vector<pair<long long, long long>> temp;
        for (int i = 0; i < n; i++)
        {
            int time;
            if (arr2[i] % power == 0)
            {

                time = arr2[i] / power;
            }
            else
            {
                time = arr2[i] / power + 1;
            }
            sum += arr1[i];
            temp.push_back({arr1[i], time});
        }
        sort(temp.begin(), temp.end(), cmp);
        long long res = 0;
        for (auto i : temp)
        {

            res += (i.second) * sum;
            sum -= i.first;
        }
        return res;
    }
};