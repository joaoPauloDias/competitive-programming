#include <bits/stdc++.h>

using namespace std;

#define range(x, l, u) (long long x = (l); x < (u); x++)
#define let auto
#define debug_var(x) #x " = " << (x)

const int MAXL = 1005;

vector<vector<int>> adj(MAXL, vector<int>(0));
int asking[MAXL];
bool loser[MAXL];
bool visited[MAXL];
int acc[MAXL];
int n;


void bfs(int u){
    visited[u]=true;
    queue<int> q;
    q.push(u);
    while(!q.empty()){
        int s = q.front(); q.pop();
        for(auto v: adj[s]){
            if(visited[v]){
                loser[s]|=true;
                continue;
            }
            visited[v] = true;
            q.push(v);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i = 0; i<n; i++){
        int a, b; cin>>a>>b;
        a--; b--;
        adj[i].push_back(a);
        asking[a]++;
        adj[i].push_back(b);
        asking[b]++;
    }

    for(int i = 0; i<n; i++){
        memset(visited, false, sizeof(visited));
        bfs(i);
    }
    for(int i = 0; i <n; i++){
        if(loser[i])cout<<"Y";
        else cout<<"N";
    }
    cout<<endl;
    return 0;
}