#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 +7;
const int INF = 1e9 +5;
const int MAXL = 1e6+5;

int dp[105][MAXL];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x; cin>>n>>x;
    int coins[n];

    for(int i = 0; i <n; i++)
        cin>>coins[i];
 
 
    dp[0][0] = 1;
   
    for(int j = 0; j<n; j++){
        for(int i = 0; i<=x; i++){
            if(i+coins[j]<=x){
                dp[j][i+coins[j]]=(dp[j][i+coins[j]] + dp[j][i])%MOD;
            }
            dp[j+1][i]=(dp[j+1][i]+ dp[j][i])%MOD;
        }
   }
 
    cout<<dp[n-1][x]<<endl;
}