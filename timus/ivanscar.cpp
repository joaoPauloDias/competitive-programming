#include <bits/stdc++.h>

using namespace std;

const int INF  = 1e9;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

int main(){
    int n, m; cin>>n>>m;

    vector<vector<pii>> adj(n+5, vector<pii>());

    while(m--){
        int a, b; cin>>a>>b;
        adj[a].emplace_back(b, 0);
        adj[b].emplace_back(a, 1);
    }
    
    int orig, dest;
    cin>>orig>>dest;

    vector<vector<int>>  d(n+5, vector<int>(2, INF));
    
    d[orig][0] = d[orig][1] = 0;

    priority_queue<tiii, vector<tiii>, greater<tiii>> q;

    q.emplace(0, orig, 0);
    q.emplace(0, orig, 1);

    while(!q.empty()){
        auto [d_v, v, t_v] = q.top();
        q.pop();

        if(d_v > d[v][t_v])
            continue;
    
        for(auto [u, t_u] : adj[v]){
            if(d_v + (t_u!=t_v) < d[u][t_u]){
                d[u][t_u] = d_v + (t_u!=t_v);
                q.emplace(d[u][t_u], u, t_u);
            }
        }
    }

    cout<<min(d[dest][1], d[dest][0])<<endl;

}