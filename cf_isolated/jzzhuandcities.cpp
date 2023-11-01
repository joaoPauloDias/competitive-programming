#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 1e17;
using pii = pair<ll, ll>;
using tiii = pair<ll,ll,ll>;

int main(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<tiii>> adj(n+5, vector<tiii>());

    while(m--){
        int u, v, x;
        cin>>u>>v>>x;
        adj[u].emplace_back(v, x, 0);
        adj[v].emplace_back(u, x, 0);
    }

    while(k--){
        int s, y;
        cin>>s>>y;
        adj[1].emplace_back(s, y, 1);
        adj[s].emplace_back(1, y, 1);
    }

    priority_queue<tiii, vector<tiii>, greater<tiii>> q;
    vector<vector<ll>> d(n+5, vector<ll> (2, INF));

    d[1][0] = d[1][1] = 0;

    q.emplace(0, 1, 0);
    q.emplace(0, 1, 1);

    while(!q.empty()){
        auto [d_v, v, t_v] = q.top();
        q.pop();
        if(d_v>d[v][t_v])
            continue;
        for(auto [u, len, t_u]:adj[v]){
            if(d[u]>d_v + len){
                d[u] = 
            }
        }
    }

}