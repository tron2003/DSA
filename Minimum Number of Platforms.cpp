int calculateMinPatforms(int arr1[], int arr2[], int n)
{
    // Write your code here.

    int res = INT_MIN;
    sort(arr1, arr1 + n);
    sort(arr2, arr2 + n);
    int temp = 0;
    int i = 0;
    int j = 0;
    while (i < n)
    {

        if (arr1[i] <= arr2[j])
        {

            temp++;
            i++;
        }
        else
        {
            temp--;
            j++;
        }
        res = max(res, temp);
    }
    return res;
}