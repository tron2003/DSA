#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void bfs(vector<vector<int>>adj,int v,int s){
    bool vis[v + 1]={false};
    queue<int> que;
    vis[s] = true;
    que.push(s);
    while(!que.empty()){
        auto curr = que.front();
        que.pop();
        cout << curr << " ";
        for(auto n:adj[curr]){
            if(vis[n]==false){
                // cout << vis[n] << " ";
                vis[n] = true;
                que.push(n);
            }
        }
    }
}

int main()
{
    int v = 5;
    vector<vector<int>> adj(v + 1);

    // Add edges
    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(4);
    adj[3].push_back(5);

    int source = 1;
    cout << "BFS Traversal: ";
    bfs(adj, v, source);
    cout << endl;

    return 0;
}
