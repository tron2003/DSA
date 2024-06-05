#include <iostream>
#include <vector>
using namespace std;

void helper(string str, string arr[], string temp, int i, vector<string> &res)
{
    if (i >= str.length())
    {
        res.push_back(temp);
        return;
    }

    int num = str[i] - '0'; // Convert character to corresponding digit
    if (num < 0 || num >= 10)
        return; // Ensure the digit is within bounds

    string val = arr[num];

    for (int j = 0; j < val.length(); j++)
    {
        temp.push_back(val[j]);
        helper(str, arr, temp, i + 1, res);
        temp.pop_back();
    }
}

void func(string str)
{
    string arr[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> res;
    string temp = "";
    int i = 0;
    helper(str, arr, temp, i, res);

    for (auto x : res)
    {
        cout << x << endl;
    }
}

int main()
{
    string str = "234"; // Example input with digits
    func(str);
    return 0;
}
