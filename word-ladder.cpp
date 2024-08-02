class Solution
{
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string> &wordList)
    {

        unordered_set<string> set(wordList.begin(), wordList.end());
        queue<pair<string, int>> que;

        que.push({beginWord, 1});
        set.erase(beginWord);
        while (!que.empty())
        {

            auto front = que.front().first;
            int step = que.front().second;
            que.pop();
            if (front == endWord)
            {
                return step;
            }
            for (int i = 0; i < front.size(); i++)
            {

                char ori = front[i];
                for (char k = 'a'; k <= 'z'; k++)
                {
                    front[i] = k;
                    if (set.find(front) != set.end())
                    {
                        set.erase(front);
                        que.push({front, step + 1});
                    }
                }
                front[i] = ori;
            }
        }
        return 0;
    }
};