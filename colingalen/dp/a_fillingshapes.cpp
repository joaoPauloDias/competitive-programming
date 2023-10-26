#include <bits/stdc++.h>
using namespace std;

typedef long long int  ll;
int main(){
    int n; cin>>n;
    ll dp[n+1] = {0};
    dp[2] = 2;
    for(int i = 2; i<=n/2; i++){
        dp[i*2] = dp[(i-1)*2]*2;
    }
    cout<<dp[n]<<endl;
}