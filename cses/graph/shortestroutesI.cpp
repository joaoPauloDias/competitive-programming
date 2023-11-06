#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

using pll = pair<ll, ll>;
const ll INF = 1e15;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m; cin>>n>>m;
    vector<vector<pll>> adj(n+5, vector<pll>());
    while(m--){
        int a, b, c;cin>>a>>b>>c;
        adj[a].emplace_back(b, c);
    }

    vector<ll> d(n+5, INF);
    priority_queue<pll, vector<pll>, greater<pll>> q;

    q.emplace(0, 1);
    while(!q.empty()){
        auto [dv, v] = q.top(); q.pop();
        if(dv>=d[v])continue;
        d[v] = dv;
        for(auto [u, de] : adj[v]){
            if(dv+de<d[u]){
                q.emplace(dv+de, u);
            }
        }
    }

    for(int i = 1; i<=n; i++){
        cout<<d[i]<<' ';
    }
    cout<<endl;
    return 0;
}