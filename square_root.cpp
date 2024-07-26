
#include<iostream>
using namespace std;
#define mod 1000000009

int helper(int x)
{
    int l = 0;
    int h = x;
    long long res = 0;
    while (l <= h)
    {

        long long mid = l + (h - l) / 2;
        long long temp = (mid) * (mid);
        if (temp == x)
        {
            return mid;
        }
        if (x > temp)
        {
            res = mid;
            l = mid + 1;
        }
        else
        {
            h = mid - 1;
        }
    }

    return res;
}
double func(int n,int p,int temp){

    double factor = 1;
    double ans = temp;
    for (int i = 0; i < p;i++){

        factor = factor / 10;
        for (double j = ans; j * j < n;j+=factor){
            ans = j;
        }
    }
    return ans;
}

int main()
{

    int res = helper(12);

    cout << func(12, 3, res);
    return 0;
}