//https://cses.fi/problemset/task/1679/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<int> vis;
stack<int> s;
vector<vector<int>> adj;

void dfs(int u)
{
    vis[u]=1;
    for(auto v:adj[u])
    {
        if(!vis[v])
        dfs(v);
        else if(vis[v]==1)
        {
            cout << "IMPOSSIBLE\n";//if a node is visited,and that node is not is stack(i.e vis!=2) then the graph is cyclic
            exit(0);
        }   
    }
    vis[u]=2;
    s.push(u);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    adj.assign(n + 1, {});
    vis.assign(n + 1, 0);
 
    for (int i = 0; i < m; i++)
    {
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        dfs(i);
    }
    
    while(!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}

