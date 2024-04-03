#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool func(string str)
{

    stack<int> st;

    for (auto x : str)
    {
        if (x == '{' || x == '(' || x == '[')
        {

            st.push(x);
        }
        else
        {

            if (st.empty())
            {
                return false;
            }
            else
            {

                if (x == ')' || x == '}' || x == ']')
                {
                    st.pop();
                }
            }
        }
    }
    return st.empty() == true ? true : false;
}

int main()
{

    string str = "{({)}";
    cout << func(str);

    return 0;    
}