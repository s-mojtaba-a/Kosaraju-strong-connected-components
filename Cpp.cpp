#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

template <typename T>
void dfs1(const T v, stack<T> &finish_time, const vector<vector<T>> &adj, bool mark[])
{
    mark[v] = 1;
    for (T i : adj[v])
    {
        if (mark[i] == 0)
        {
            dfs1(i, finish_time, adj, mark);
        }
    }
    finish_time.push(v);
}

template <typename T>
void dfs2(const T v, const vector<vector<T>> &adj, bool mark[], vector<T> &component)
{
    mark[v] = 1;
    component.emplace_back(v);
    for (T i : adj[v])
    {
        if (mark[i] == 0)
        {
            dfs2(i, adj, mark, component);
        }
    }
}

template <typename T>
void reverse_edge(const T &n, const vector<vector<T>> &adj1, vector<vector<T>> &adj2)
{
    // n = number of vertices
    // adj1 = adjacency list
    // adj2 = new adjacency list ( after reversing )
    // vertices are numbered from 1 to n
    for (T i = 1; i <= n; i++)
    {
        for (T j : adj1[i])
        {
            adj2[j].emplace_back(i);
        }
    }
}

template <typename T>
void kosaraju(const T &n, const vector<vector<T>> &adj, vector<vector<T>> &components)
{
    stack<T> fin;
    bool mark[n + 1] = {0};
    for (T i = 1; i <= n; i++)
    {
        if (mark[i] == 0)
        {
            dfs1(i, fin, adj, mark);
        }
    }
    vector<vector<T>> adj2(n + 1);
    reverse_edge(n, adj, adj2);
    vector<T> component;
    memset(mark, 0, sizeof(mark));
    while (!fin.empty())
    {
        T v = fin.top();
        fin.pop();
        if (mark[v] == 0)
        {
            dfs2(v, adj2, mark, component);
            components.push_back(component);
            component.clear();
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    /* int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].emplace_back(b);
    }
    vector<vector<int>> ans;
    kosaraju(n, adj, ans); // ans contains strongly connected components of the graph
    for (auto i : ans)
    {
        for (int j : i)
            cout << j << " ";
        cout << '\n';
    } */
}
