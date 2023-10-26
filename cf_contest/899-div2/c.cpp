#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t;

    while(t--){
        int n; cin>>n;
        ll a[n+1];
        
        for(int i = 1; i<=n; i++){
            cin>>a[i];
        }
        
        ll dp[n+5][2];
        memset(dp, 0, sizeof(dp));
        //maximo que consigo chegar no estado i na paridade j
        
        dp[1][0] = a[1];
        dp[1][1] = 0;
        for(int i = 2; i<=n; i++){
            
            if(i%2){
                //se o atual estiver na paridade correta
                dp[i][0] = max({dp[i-1][0],dp[i-1][1], dp[i-1][1]+a[i]});
                dp[i][1] = max({dp[i-1][1], dp[i-1][0]});
            }else{
                dp[i][1] = max({dp[i-1][1],dp[i-1][0], dp[i-1][0]+a[i]});
                dp[i][0] = max({dp[i-1][1], dp[i-1][0]});
            }
        }

        // for(int i = 1; i<=n; i++){
        //     cout<<i<<": " <<dp[i][0]<<' '<<dp[i][1]<<endl;
        // }

        cout<<max(dp[n][0], dp[n][1])<<endl;
        //cout<<soma<<endl;

        
    }
    return 0;
}