#include <bits/stdc++.h>
using namespace std;

const int N = 10005;

int n, x;

vector<int> g[N];

bool vis[N];

bool good[N];

int cnt;

void ADD_EDGE(int u, int v)
{
    g[u].push_back(v);
}

void dfs1(int v)
{
    good[v] = true;
    for (auto to : g[v])
        if (!good[to])
            dfs1(to);
}

void dfs2(int v)
{
    vis[v] = true;
    ++cnt;
    for (auto to : g[v])
        if (!vis[to] && !good[to])
            dfs2(to);
}

int Minimum_Edges()
{
    dfs1(x);
    vector<pair<int, int> > val;

    for (int i = 0; i < n; ++i) {

        if (!good[i]) {
            cnt = 0;
            memset(vis, false, sizeof(vis));

            dfs2(i);
            val.push_back(make_pair(cnt, i));
        }
    }


    sort(val.begin(), val.end());
    reverse(val.begin(), val.end());

    int ans = 0;
    for (auto it : val) {
        if (!good[it.second]) {
            ++ans;
            dfs1(it.second);
        }
    }

    return ans;
}

int main()
{
    int m, r = 0;
    cin>>n>>m;
    for(int i = 0; i <m; i++){
        int a1, a2;
        cin>>a1>>a2;
        ADD_EDGE(a1-1, a2-1);


    }
    for(int i = 0; i<n; i++){
        x = i;
        r+=Minimum_Edges();
    }
    cout << Minimum_Edges();

    return 0;
}
