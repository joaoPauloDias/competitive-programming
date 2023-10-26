#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 +7;
int main(){

    int n; cin>>n;
    ll dp[n+1] = {0};
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i<=n; i++){
        for(int j = 1; j<=6; j++){
            if(i-j>=0){
                dp[i] += dp[i-j];
                dp[i]%=MOD;
            }
        }
    }
    cout<<dp[n]<<endl;
}