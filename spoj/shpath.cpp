#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int INF = 1e9;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int s; cin>>s;
    while(s--){
        int n; cin>>n;
        map<string, int> city;
        vector<vector<pair<int, int>>> adj(n+5, vector<pair<int, int>>());
        for(int i = 1; i<=n; i++){
            string name;
            cin>>name;
            city[name] = i;
            int aux; cin>>aux;
            while(aux--){
                int dest, dist;
                cin>>dest>>dist;
                adj[i].push_back({dest, dist});
            }
        }
        int t; cin>>t;
        while(t--){
            string a, b;cin>>a>>b;
            int c1 = city[a], c2 = city[b]; 
            int d[n+5];
            for(int i = 0; i<=n; i++)d[i] = INF;
            d[c1] = 0;
            using pii = pair<int, int>;
            priority_queue<pii, vector<pii>, greater<pii>> q;
            q.push({0, c1});
            while(!q.empty()){
                int v = q.top().second;
                int d_v = q.top().first;
                q.pop();
                if(d_v != d[v])
                    continue;

                for(auto edge : adj[v]){
                    if(d[v]+ edge.second < d[edge.first]){
                        d[edge.first] = d[v]+ edge.second;
                        q.push({d[edge.first], edge.first});
                    }
                }
            }

            
            cout<<d[c2]<<endl;

        }

    }
    
    return 0;
}