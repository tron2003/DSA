#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<char> func(string str)
{
    vector<char> res;
    stack<char> st;
    char arr[] = {'^', '/', '*', '+', '-'};
    unordered_map<char, int> mp;
    mp.insert({'^', 4});
    mp.insert({'/', 3});
    mp.insert({'*', 2});
    mp.insert({'+', 1});
    mp.insert({'-', 0});

    for (auto x : str)
    {

        if (x >= 'a' && x <= 'z')
        {
            res.push_back(x);
        }
        else if (x == '(')
        {

            st.push(x);
        }
        else if (x == ')')
        {
            while (st.top() != '(' && st.empty() == false)
            {

                res.push_back(st.top());
                st.pop();
            }

            st.pop();
        }
        else if (mp.find(x)!=mp.end())
        {

            if (st.empty())
            {
                st.push(x);
            }
            else
            {
                while (!st.empty() && mp[x] <= mp[st.top()] && st.top() != '(')
                {
                    res.push_back(st.top());
                    st.pop();
                }
                st.push(x);
            }
        }
    }
    while (!st.empty())
    {
        res.push_back(st.top());
        st.pop();
    }

    return res;
}

int main()
{

    string str = "(a+(b*(c-d)))";
    vector<char> res;
    res = func(str);
    for (auto x : res)
    {
        cout << x << ' ';
    }

    return 0;
}