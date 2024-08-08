int func(int mid, int n, int m)
{
    long long temp = 1;
    for (int i = 0; i < n; i++)
    {
        temp *= mid;
        if (temp > m)
        {

            return 2;
        }
    }
    if (temp == m)
    {

        return 1;
    }
    return 0;
}
int NthRoot(int n, int m)
{
    // Write your code here.
    int low = 1;
    int high = m;
    int res = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        long long temp = 1;
        int k = func(mid, n, m);
        if (k == 1)
        {

            return mid;
        }
        else if (k == 0)
        {

            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return res;
}