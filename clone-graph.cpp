/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution
{
public:
    Node *dfs(Node *node, unordered_map<Node *, Node *> &mp)
    {
        vector<Node *> arr;
        Node *curr = new Node(node->val);
        mp[node] = curr;

        for (auto it : node->neighbors)
        {

            if (mp.find(it) != mp.end())
            {

                arr.push_back(mp[it]);
            }
            else
            {
                arr.push_back(dfs(it, mp));
            }
        }
        curr->neighbors = arr;
        return curr;
    }
    Node *cloneGraph(Node *node)
    {
        unordered_map<Node *, Node *> mp;
        if (node == 0)
        {
            return NULL;
        }

        else if (node->neighbors.size() == 0)
        {
            Node *temp = new Node(node->val);
            return temp;
        }
        return dfs(node, mp);
    }
};