#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ll;
ll mod = 1e9 +7;
int main(){
    int n; cin>>n;
    int alvo = n*(n+1)/2;
    
    if(alvo%2){
        cout<<0<<endl;
        return 0;
    }
    alvo/=2;
    ll dp[alvo+1];
    for(int i = 0; i<=alvo; i++)dp[i] = 0LL;
    dp[0] = 1;
    //sacada, fazer a dp até N-1:
    //pq o N sempre estará no outro conjunto
    for(int i = 2; i<=n; i++){
        for(int j = alvo; j>=0; j--){
            if(i+j<=alvo)dp[i+j] =(dp[i+j] + dp[j])%mod;
        }
    }
    cout<<dp[alvo]<<endl;
}