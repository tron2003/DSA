double median(vector<int> &a, vector<int> &b)
{
    int n1 = a.size();
    int n2 = b.size();
    int n = n1 + n2;
    int idx1 = (n - 1) / 2; // Index of the first middle element
    int idx2 = n / 2;       // Index of the second middle element
    int cnt = 0;
    int i = 0;
    int j = 0;
    int num1 = -1;
    int num2 = -1;

    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
        {
            if (cnt == idx1)
            {
                num1 = a[i];
            }
            if (cnt == idx2)
            {
                num2 = a[i];
            }
            i++;
        }
        else
        {
            if (cnt == idx1)
            {
                num1 = b[j];
            }
            if (cnt == idx2)
            {
                num2 = b[j];
            }
            j++;
        }
        cnt++;
    }

    while (i < n1)
    {
        if (cnt == idx1)
        {
            num1 = a[i];
        }
        if (cnt == idx2)
        {
            num2 = a[i];
        }
        i++;
        cnt++;
    }

    while (j < n2)
    {
        if (cnt == idx1)
        {
            num1 = b[j];
        }
        if (cnt == idx2)
        {
            num2 = b[j];
        }
        j++;
        cnt++;
    }

    if (n % 2 == 1)
    {
        return (double)num2;
    }

    return (double)(num1 + num2) / 2.0;
}
