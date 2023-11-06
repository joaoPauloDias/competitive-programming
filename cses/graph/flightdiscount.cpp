#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF = 1e15;

using pll = pair<ll,ll>;
using tlll = tuple<ll,int,ll>;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m; cin>>n>>m;
    vector<vector<pll>> adj(n+5, vector<pll>());
    while(m--){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].emplace_back(b,c);
    }
    vector<vector<ll>> d(n+5, vector<ll>(2, INF));
    priority_queue<tlll, vector<tlll>, greater<tlll>> q;
    q.emplace(0,0,1);
    while(!q.empty()){
        auto [dv, tk, v] = q.top();
        q.pop();
        if(dv>=d[v][tk])continue;
        d[v][tk] = dv;
        for(auto [u, de] : adj[v]){
            if(dv+de<d[u][tk]){
                q.emplace(dv+de, tk, u);
            }
            if(!tk && dv+(de/2)<d[u][!tk]){
                q.emplace(dv+(de/2), !tk, u);
            }
        }
    }

    cout<<d[n][1]<<endl;

    return 0;
}