#include <iostream>
#include <bits/stdc++.h>
using namespace std;

double  func(vector<int> w, vector<int> v, int n, int a)
{
double res = 0;
    vector<pair<int, int>> temp(n,{0,0});

    for (int i = 0; i < n; i++)
    {

        temp[i] ={v[i], w[i]};
    }

    sort(temp.begin(), temp.end(), []( pair<int, int> &a,  pair<int, int> &b)
         { double a1 = double (a.first) / a.second;
        double b1 = double(b.first) / b.second;
        return a1 > b1; });

    for (int i = 0; i < n; i++)
    {

        if (temp[i].second <= a)
        {

            a -= temp[i].second;
            res += temp[i].first;
        }
        else
        {
            res += temp[i].first * (double(a) / temp[i].second);
            break;
        }
    }
    cout << res << endl;
    return res;
}

int main()
{
    vector<int> w = {50, 20, 30};
    vector<int> v = {600, 500, 400};
    cout << func(w, v, 3, 70);

    return 0;
}