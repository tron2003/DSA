#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<char> func(string str)
{
    vector<char> res;
    stack<char> st;
    unordered_map<char, int> mp;
    mp.insert({'^', 5});
    mp.insert({'/', 4});
    mp.insert({'*', 3});
    mp.insert({'+', 2});
    mp.insert({'-', 1});
    for (int i = str.size(); i >= 0; i--)
    {

        if (str[i] >= 'a' && str[i] <= 'z')
        {
            res.push_back(str[i]);
        }
        else if (str[i] == ')')
        {
            st.push(str[i]);
        }
        else if (str[i] == '(')
        {

            while (st.empty() == false && st.top() != ')')
            {
                res.push_back(st.top());
                st.pop();
            }
            st.pop();
        }
        else

        {
            if(st.empty()){
                st.push(str[i]);
                continue;
            }
            while (st.empty() == false && st.top() != '(' && mp[str[i]] <= mp[st.top()])
            {

                res.push_back(st.top());
                st.pop();
            }
            st.push(str[i]);
        }
    }
    while (st.empty() == false)
    {
        res.push_back(st.top());
        st.pop();
    }
    reverse(res.begin(), res.end());

    return res;
}

int main()
{
    string str = "(x+(y*(z-w)))";
    vector<char> res = func(str);
    for (auto x : res)
    {
        cout << x << " ";
    }
    return 0;
}