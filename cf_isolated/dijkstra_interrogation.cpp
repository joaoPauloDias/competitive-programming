#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 1e17;

using pii = pair<ll, ll>;
int main(){
    int n, m; 
    cin>>n>>m;
    vector<vector<pii>> adj(n+5, vector<pii>());
    
    while(m--){
        int a, b;
        ll w;
        cin>>a>>b>>w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }

    vector<ll> dist(n+5, INF);
    vector<int> parent(n+5, -1);
    dist[1] = 0;
    parent[1] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> q;

    q.push({0, 1});

    while(!q.empty()){
        pii a = q.top();
        q.pop();
        if(a.first != dist[a.second])
            continue;
        for(auto x: adj[a.second]){
            if(dist[x.first]>x.second + dist[a.second]){
                dist[x.first] = x.second + dist[a.second];
                parent[x.first] = a.second;
                q.push({dist[x.first], x.first});
            }
        }
    }
    if(dist[n]==INF){
        cout<<-1<<endl;
        return 0;
    }
    
    int atual = n;
    vector<int> route;
    while(atual!=0){
        route.push_back(atual);
        atual = parent[atual];
    }
    reverse(route.begin(), route.end());
    for(auto i : route){
        cout<<i<<' ';
    }
    cout<<endl;

    return 0;


}