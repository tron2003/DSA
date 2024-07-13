#include<bits/stdc++.h>
#include<iostream>
using namespace std;
class Solution
{
public:
    string minWindow(string s, string t)
    {
        int m = s.size();
        int n = t.size();
        vector<int> arr(256, 0);
        for (auto x : t)
        {
            arr[x]++;
        }
        int l = 0;
        int r = 0;
        int sidx = -1;
        int smin = 1e9;
        int cnt = 0;
        while (r < m)
        {

            if (arr[s[r]] > 0)
            {
                cnt++;
            }
            arr[s[r]]--;
            while (cnt == n)
            {

                if (r - l + 1 < smin)
                {
                    smin = r - l + 1;
                    sidx = l;
                }
                arr[s[l]]++;
                if (arr[s[l]] > 0)
                {
                    cnt--;
                }
                l++;
            }
            r++;
        }

        return sidx == -1 ? "" : s.substr(sidx, smin);
    }
};
int main(){
    return 0;
}