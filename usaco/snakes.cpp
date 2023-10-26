#include <bits/stdc++.h>

using namespace std;

int main(){

    //freopen("hps.in", "r", stdin);
    //freopen("hps.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin>>n>>k;
    int dp[n+1][k+1];
    //dp[i][j] vai guardar o tamanho minimo das primeiras i redes usando j transiçoes
    int s[n+1];
    int sum = 0;
    
    for(int i = 0; i < n; i++){
        cin>>s[i];
        sum+=s[i];
    }

    int min_start = 0;
    for(int i = 0; i < n; i++){
        min_start = max(min_start, s[i]);
        dp[i][0] = min_start*(i+1);

        for(int l = 0; l<= k; l++){
            dp[i][l] = 1e9;
            int net_s = s[i];
            for(int j = i-1; j>=0; j--){
                dp[i][l] = min(dp[i][l], dp[j][l])
            }
        }
    }

   
    return 0;
}