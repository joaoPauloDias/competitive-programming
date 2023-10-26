#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF = 1e15; 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin>>n;
    ll s[n], w[n];
    for(int i = 0; i<n; i++)cin>>s[i];    
    
    for(int i = 0; i<n; i++)cin>>w[i];

    ll dp[n+1][4];
    //indice da maior placa que utilizei ate o momento
    //numero de placas que usei
    for(int i = 0; i<=n; i++){
        for(int j = 0;j <4; j++){
            dp[i][j] = INF;
        }
        dp[i][0] = 0LL;
        dp[i][1] = w[i];
    }
    //dp[0][1] = w[0];
    
    //para cada placa
    for(int i = 0; i<n; i++){
        //vou ver todas placas que podem ser utilizadas
        for(int j = 0; j<i; j++){
            if(s[i]>s[j]){
                for(int k = 3; k>=1; k--){
                    dp[i][k] = min(dp[i][k], dp[j][k-1]+w[i]);
                }
            }
            
        }
    }
    ll ans = INF;
    for(int i = 0; i<n; i++){
        //cerr<<i<<" : "<<dp[i][3]<<endl;
        ans = min(ans, dp[i][3]);
    }
    if(ans == INF)ans = -1;
    cout<<ans<<endl;
    return 0;
}