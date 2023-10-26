#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k; cin>>n>>k;
    ll dp[n+1][k+1];
    const int MOD = 1e9 + 7;
    memset(dp, 0LL, sizeof(dp));
    for(int i = 0; i<=n; i++){
        dp[i][0] = 1;
    }
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=i; j++){
            if(i%j==0){
                for(int l = 0; l<k; l++){
                    dp[i][l+1]= (dp[i][l+1]+ dp[j][l])%MOD;
                }
            }
        }
    }

    ll ans = 0;
    for(int i = 1; i<=n; i++){
        ans = (ans +dp[i][k-1])%MOD;
    }
    cout<<ans<<endl;
    
    return 0;
}