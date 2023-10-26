#include <bits/stdc++.h>

using namespace std;

int main(){

    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k; cin>>n>>k;
    int dp[n+5][k+5][5];
    int p[n+5];
    for(int i = 1; i<=n; i++){
        char aux; cin>>aux;
        if(aux=='S')p[i]=1;
        if(aux=='P')p[i]=0;
        if(aux=='H')p[i]=2;
    }
    //0 -> paper
    //1 -> scissors
    //2 -> hoof
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i<=n; i++){
        for(int j = 0; j<=k; j++){
            for(int l = 0; l<=2; l++){
                if((l==0 && p[i]==2) || (l==1 && p[i]==0) || (l==2 && p[i]==1))dp[i][j][l]++;
                dp[i+1][j][l] = max(dp[i+1][j][l], dp[i][j][l]);//fica
                dp[i+1][j+1][0] = max(dp[i+1][j+1][0], dp[i][j][l]);//muda
                dp[i+1][j+1][1] = max(dp[i+1][j+1][1], dp[i][j][l]);//muda
                dp[i+1][j+1][2] = max(dp[i+1][j+1][2], dp[i][j][l]);//muda
            }
        }
    }

    cout<<max(dp[n][k][0],max(dp[n][k][1],dp[n][k][2]))<<endl;
    
    return 0;
}