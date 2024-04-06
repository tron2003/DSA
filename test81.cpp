#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int func(string str)
{
    int res = 0;
    stack<int> st;
    reverse(str.begin(),str.end());
    for (int i = 0; i < str.size(); i++)
    
    {

        if (str[i] >= '0' && str[i] <= '9')
        {
            st.push((str[i]) - '0');
        }
        else
        {

            int x = st.top();
            st.pop();
            int y = st.top();
            st.pop();
            if (str[i] == '*')
            {
                int res = x * y;
                st.push(res);
            }
            else if (str[i] == '/')
            {
                st.push(x / y);
            }
            else if (str[i] == '+')
            {
                int res = x + y;
                st.push(res);
            }
            else if (str[i] == '-')
            {
                st.push(x - y);
            }
        }
    }

    return st.top();
}

int main()
{
    string str = "+*123";
    cout << func(str);
    //    for(auto x:res){
    //     cout<<x<<" ";
    //    }
    return 0;
}