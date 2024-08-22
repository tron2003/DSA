//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int *constructST(int arr[], int n);

int RMQ(int st[], int n, int a, int b);
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++)
            cin >> A[i];
        int Q;
        cin >> Q;

        int *segTree = constructST(A, N);

        for (int i = 0; i < Q; i++)
        {
            int start, e;

            cin >> start >> e;
            if (start > e)
            {
                swap(start, e);
            }
            cout << RMQ(segTree, N, start, e) << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends

/* The functions which
builds the segment tree */

void build(int i, int l, int h, int arr[], int temp[])
{

    if (l == h)
    {
        temp[i] = arr[l];
        return;
    }
    int mid = l + (h - l) / 2;
    build(2 * i + 1, l, mid, arr, temp);
    build(2 * i + 2, mid + 1, h, arr, temp);
    temp[i] = min(temp[2 * i + 1], temp[2 * i + 2]);
}
int range(int i, int l, int h, int s, int e, int temp[])
{

    if (s > h || e < l)
    {

        return 1e9;
    }
    int mid = l + (h - l) / 2;
    if (l >= s && e >= h)
    {
        return temp[i];
    }
    return min(range(2 * i + 1, l, mid, s, e, temp), range(2 * i + 2, mid + 1, h, s, e, temp));
}
int *constructST(int arr[], int n)
{
    int *temp = new int[4 * n];
    // Your code here
    build(0, 0, n - 1, arr, temp);
    return temp;
}

/* The functions returns the
 min element in the range
 from a and b */
int RMQ(int st[], int n, int a, int b)
{
    // int *temp = constructST(st,n);
    int res = range(0, 0, n - 1, a, b, st);
    return res;
    // Your code here
}