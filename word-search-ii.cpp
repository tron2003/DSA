class Solution
{
public:
    struct TrieNode
    {
        unordered_map<char, TrieNode *> children;
        string word;
    };

    // Build the Trie from the given words list
    TrieNode *buildTrie(vector<string> &words)
    {
        TrieNode *root = new TrieNode();
        for (string &word : words)
        {
            TrieNode *node = root;
            for (char c : word)
            {
                if (!node->children.count(c))
                {
                    node->children[c] = new TrieNode();
                }
                node = node->children[c];
            }
            node->word = word; // Store the word at the end node
        }
        return root;
    }

    void dfs(int i, int j, vector<vector<char>> &board, TrieNode *node, vector<string> &result)
    {
        // Boundary check and visited check (we use a special character to mark visited cells)
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] == '#')
        {
            return;
        }

        char c = board[i][j];
        if (!node->children.count(c))
        {
            return; // No matching child in the Trie, so stop
        }

        node = node->children[c];
        if (!node->word.empty())
        { // Found a valid word
            result.push_back(node->word);
            node->word = ""; // Avoid duplicate results
        }

        // Mark the current cell as visited
        board[i][j] = '#';

        // Explore all four directions
        dfs(i - 1, j, board, node, result); // up
        dfs(i + 1, j, board, node, result); // down
        dfs(i, j - 1, board, node, result); // left
        dfs(i, j + 1, board, node, result); // right

        // Restore the cell after the recursion (backtracking)
        board[i][j] = c;
    }

    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        TrieNode *root = buildTrie(words); // Build the Trie
        vector<string> result;

        // Traverse the board
        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[0].size(); ++j)
            {
                dfs(i, j, board, root, result); // Perform DFS search starting from each cell
            }
        }

        return result;
    }
};
