#include <bits/stdc++.h>
#define MAXL 200005
using namespace std;
//unifinished
int blacks[MAXL];
vector<int> neigh[MAXL];
int visited[MAXL];

int dfs(int atual){
    visited[atual] = 1;

}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        int c[n];
        for(int i = 0; i<n; i++){
            cin>>c[i];
        }
        blacks[c[0]]=1;
        for(int i = 0; i<n; i++){
            int a, b;
            cin>>a>>b;
            neigh[a].push_back(b);
            neigh[b].push_back(a);
        }

    }
}
