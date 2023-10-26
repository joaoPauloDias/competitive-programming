#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 +7;
const int INF = 1e9 +5;

int main(){
    int n, m;
    cin>>n>>m;
    ll dp[n+5][m+5];
    memset(dp, 0, sizeof(dp));
    int s[n+5];
    for(int i = 1; i<=n; i++){
        cin>>s[i];
    }
    if(s[1]!=0)dp[0][s[1]] = 1;
    else{
        for(int i = 1; i<=m; i++)dp[1][i] = 1;
    }
    for(int i = 1; i <=n; i++){
        if(s[i]!=0){
            dp[i][s[i]] = (dp[i-1][s[i]-1]+dp[i-1][s[i]]+dp[i-1][s[i]+1])%MOD;
        }else{
            for(int j = 1; j<=m; j++){
                dp[i][j] += dp[i-1][j-1]+dp[i-1][j]+dp[i-1][j+1];
                dp[i][j]%=MOD;
            }
        }
        
    }
    int resp = 0;
    for(int j = 1; j<=m; j++){
           resp+=dp[n][j];
           resp%=MOD;
    }
    cout<<resp<<endl;
}