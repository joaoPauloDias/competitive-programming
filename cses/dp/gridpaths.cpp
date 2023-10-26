#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 +7;
const int INF = 1e9 +5;

int main(){
    int n; cin>>n;
    vector<vector<int>> grid(n, vector<int>(n, 0));
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for(int i = 0 ; i< n; i++){
        for(int j  =0 ; j<n; j++){
            char aux; cin>>aux;
            if(aux=='*')grid[i][j]=1;
        }
    }
    dp[0][0] = !grid[0][0];
    for(int i = 1 ; i< n; i++){
        if(grid[0][i]!=1)dp[0][i] = dp[0][i-1];
        if(grid[i][0]!=1)dp[i][0] = dp[i-1][0];

    }

    for(int i = 1 ; i< n; i++){
        for(int j  =1 ; j<n; j++){
            if(grid[i][j]!=1){
                dp[i][j] = (dp[i][j-1] + dp[i-1][j])%MOD;
            }
        }
    }
    // for(int i = 1 ; i< n; i++){
    //     for(int j  =1 ; j<n; j++){
    //         cout<<dp[i][j]<<' ';
    //     }
    //     cout<<endl;
    // }
    cout<<dp[n-1][n-1]<<endl;

}