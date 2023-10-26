#include <bits/stdc++.h>
using namespace std;

typedef long long int  ll;

const ll INF = 1e17;
int main(){
    ll n, k, p; cin>>n>>k>>p;
    ll a[n];
    ll b[k];
    for(int i = 0; i<n; i++)cin>>a[i];
    sort(a, a+n);
    for(int i = 0; i<k; i++)cin>>b[i];
    sort(b, b+k);
    vector<vector<ll>> dp(k+5,vector<ll>(n+5, INF));
    dp[0][0] = 0;
    for(int i = 0; i<k; i++){
        for(int j = 0; j<=n; j++){
            dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
            if(j!=n)dp[i+1][j+1] = min(dp[i+1][j+1], max(dp[i][j], abs(a[j]-b[i])+abs(p-b[i])));
        }
    }

    cout<<dp[k][n]<<endl;


}