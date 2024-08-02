
class Solution
{
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string> &wordList)
    {
        // code here

        int level = 0;
        vector<vector<string>> res;
        vector<string> strlevel;
        unordered_set<string> set(wordList.begin(), wordList.end());
        queue<vector<string>> que;
        que.push({beginWord});

        strlevel.push_back(beginWord);
        while (!que.empty())
        {
            vector<string> temp = que.front();
            que.pop();
            if (temp.size() > level)
            {

                level++;
                for (auto x : strlevel)
                {
                    set.erase(x);
                }
            }
            string word = temp.back();
            if (word == endWord)
            {
                if (res.size() == 0)
                {
                    res.push_back(temp);
                }
                else if (res[0].size() == temp.size())
                {
                    res.push_back(temp);
                }
            }
            for (int i = 0; i < word.size(); i++)
            {

                char ori = word[i];
                for (char k = 'a'; k <= 'z'; k++)
                {

                    word[i] = k;
                    if (set.count(word) > 0)
                    {
                        temp.push_back(word);
                        que.push(temp);
                        // marking and deleting from back from level  vector of
                        // string
                        strlevel.push_back(word);
                        temp.pop_back();
                    }
                }
                word[i] = ori;
            }
        }
        return res;
    }
};