class Solution
{
public:
    bool lemonadeChange(vector<int> &arr)
    {
        int temp1 = 0;
        int temp2 = 0;

        int temp3 = 0;
        for (int i = 0; i < arr.size(); i++)
        {

            if (arr[i] == 5)
            {

                temp1++;
            }
            else if (arr[i] == 10)
            {
                if (temp1 >= 1)
                {
                    temp1--;
                    temp2++;
                }
                else
                {
                    return false;
                }
            }
            else
            {

                if (temp1 >= 1 & temp2 >= 1)
                {
                    temp1--;
                    temp2--;
                }
                else if (temp1 >= 3)
                {
                    temp1 = temp1 - 3;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};