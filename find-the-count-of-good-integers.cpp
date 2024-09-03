#define ll long long

class Solution
{
public:
    ll numberfromvector(vector<int> num)
    {

        ll res = 0;
        for (int x : num)
        {

            res = res * 10 + x;
        }
        return res;
    }
    ll fact(int n)
    {

        ll res = 1;
        for (int i = 2; i <= n; i++)
        {

            res = res * i;
        }
        return res;
    }
    ll total(map<int, int> mp, int n)
    {

        ll res = fact(n);
        for (auto i : mp)
        {

            res = res / fact(i.second);
        }
        return res;
    }
    ll zero(map<int, int> mp, int n)
    {

        if (mp.find(0) == mp.end() || mp[0] == 0)
        {
            return 0;
        }
        mp[0]--;
        ll res = fact(n - 1);
        for (auto x : mp)
        {

            res = res / fact(x.second);
        }
        return res;
    }
    ll cal(map<int, int> mp, int n)
    {

        ll res = total(mp, n) - zero(mp, n);
        return res;
    }

    ll ans = 0;
    set<map<int, int>> vis;
    void helper(vector<int> &num, int left, int right, int k, int n)
    {

        if (left > right)
        {

            ll temp = numberfromvector(num);
            if (temp % k == 0)
            {
                map<int, int> mp;
                while (temp)
                {

                    mp[temp % 10]++;
                    temp = temp / 10;
                }
                if (vis.find(mp) == vis.end())
                {
                    ans += cal(mp, n);
                    vis.insert(mp);
                }
            }
            return;
        }
        for (int digit = (left == 0) ? 1 : 0; digit <= 9; digit++)
        {
            num[left] = num[right] = digit;
            helper(num, left + 1, right - 1, k, n);
        }
    }
    long long countGoodIntegers(int n, int k)
    {
        vector<int> num(n);
        helper(num, 0, n - 1, k, n);
        return ans;
    }
};