class NumArray
{

    vector<int> arr;
    vector<int> temp;
    void build(int i, int l, int h)
    {

        if (l == h)
        {
            temp[i] = arr[l];
            return;
        }
        int mid = l + (h - l) / 2;

        build(2 * i + 1, l, mid);
        build(2 * i + 2, mid + 1, h);
        temp[i] = temp[2 * i + 1] + temp[2 * i + 2];
    }
    int query(int s, int e, int i, int l, int h)
    {

        if (e < l || s > h)
        {
            return 0;
        }
        else if (s <= l && e >= h)
        {

            return temp[i];
        }
        int mid = l + (h - l) / 2;
        return query(s, e, 2 * i + 1, l, mid) +
               query(s, e, 2 * i + 2, mid + 1, h);
    }

public:
    NumArray(vector<int> &num)
    {
        int n = num.size();
        arr = num;
        temp.resize(4 * n);
        build(0, 0, n - 1);
    }

    int sumRange(int l, int r)
    {

        int res = query(l, r, 0, 0, arr.size() - 1);
        return res;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */