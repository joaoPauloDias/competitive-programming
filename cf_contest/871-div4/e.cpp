#include <bits/stdc++.h>
#define MAXL 1005
using namespace std;

int g[MAXL][MAXL];
int v[MAXL][MAXL];
int n,m;

void dfs(int y, int x, int* soma){
    if(v[y][x] == 1 || g[y][x] == 0)return;
    v[y][x] = 1;
    (*soma) = (*soma)+g[y][x];
    for(int i = -1; i<=1; i+=2){
        if(x+i>=1 && x+i<=m)dfs(y, x+i, soma);

        if(y+i>=1 && y+i<=n)dfs(y+i, x, soma);
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        int maxr = 0, soma = 0;
        for(int i = 1; i<=n; i++)
            for(int j = 1; j<=m; j++){
                cin>>g[i][j];
                v[i][j] = 0;
            }

        for(int i = 1; i<=n; i++)
            for(int j = 1; j<=m; j++){
                if(v[i][j]==0 && g[i][j]!=0){
                    soma = 0;
                    dfs(i, j, &soma);
                    maxr = max(maxr, soma);
                }
            }

        cout<<maxr<<endl;
    }

}
