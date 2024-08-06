class Solution
{
public:
    int minFlips(vector<vector<int>> &arr)
    {
        int m = arr.size();
        int n = arr[0].size();
        int ones = 0;
        int res = 0;
        for (int i = 0; i < m / 2; i++)
        {

            for (int j = 0; j < n / 2; j++)
            {

                int cnt = 0;
                if (arr[i][j] == 1)
                {
                    cnt++;
                }
                if (arr[i][n - j - 1] == 1)
                {
                    cnt++;
                }
                if (arr[m - i - 1][j])
                {
                    cnt++;
                }
                if (arr[m - i - 1][n - j - 1])
                {
                    cnt++;
                }
                if (cnt == 4 || cnt == 0)
                {
                    ones += cnt;
                    continue;
                }
                else if (cnt >= 2)
                {
                    res += (4 - cnt);
                    ones += 4;
                }
                else
                {
                    res += cnt;
                }
            }
        }
        if (m % 2 == 0 && n % 2 == 0)
        {
            return res;
        }
        int palindrome = 0;
        int change = 0;
        if (m % 2 == 1)
        {
            for (int i = 0; i < n / 2; i++)
            {
                if (arr[m / 2][i] == 1 && arr[m / 2][n - i - 1] == 1)
                {
                    palindrome++;
                }
                if (arr[m / 2][i] != arr[m / 2][n - i - 1])
                {
                    res++;
                    change++;
                }
            }
        }
        if (n % 2 == 1)
        {
            for (int i = 0; i < m / 2; i++)
            {

                if (arr[i][n / 2] == 1 && arr[m - i - 1][n / 2] == 1)
                {
                    palindrome++;
                }
                if (arr[i][n / 2] != arr[m - i - 1][n / 2])
                {
                    res++;
                    change++;
                }
            }
        }
        if (palindrome % 2 == 1)
        {
            if (change == 0)
            {
                res += 2;
            }
        }
        if (m % 2 == 1 && n % 2 == 1 && arr[m / 2][n / 2] == 1)
        {
            res++;
        }
        return res;
    }
};