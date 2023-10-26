#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 +7;
const int INF = 1e9 +5;

int main(){

    int s, n; cin>>n>>s;
    ll coins[n];

    for(int i = 0; i<n; i++){
        cin>>coins[i];
    }

    vector<int> dp(s + 1, INF);
    dp[0] = 0;

    for(int i = 1; i<=s; i++){
        for(int j = 0; j<n; j++){
            if(i-coins[j]>=0){
                dp[i] = min(dp[i], 1+dp[i-coins[j]]);
            }
        }
    }
    if(dp[s]==INF)dp[s] = -1;
    cout<<dp[s]<<endl;
}