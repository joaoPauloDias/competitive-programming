#include <bits/stdc++.h>
using namespace std;

typedef long long int  ll;
int main(){
    int n, k; cin>>n>>k;
    char s[n+1];
    char f[k+1];
    for(int i = 1; i<=n; i++)
        cin>>s[i];
    
    for(int i = 1; i<=k; i++){
        cin>>f[i];
    }
    
    ll dp[n+1];
    dp[0] = 0;
    int atual = 0;
    for(int i = 1; i<=n; i++){
        dp[i]=dp[i-1];
        for(int j = 1; j<=k; j++){
            if(s[i]==f[j]){
                atual++;
                dp[i]+=atual;
                break;
            }
        }
        if(dp[i]==dp[i-1]){
            atual=0;
        }
    }
    cout<<dp[n]<<endl;


}