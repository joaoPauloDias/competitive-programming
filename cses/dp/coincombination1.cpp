#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 +7;
const int INF = 1e9 +5;

int main(){
    int n, x; cin>>n>>x;
    int coins[n];
    for(int i = 0; i <n; i++)
        cin>>coins[i];
    ll dp[x+1] = {0};
    dp[0] = 1;
    for(int i = 1; i <= x; i++){
        for(int j = 0; j < n; j++){
            if(i-coins[j]>=0){
                dp[i]+=dp[i-coins[j]];
                dp[i]%=MOD;
            }
        }
    }
    cout<<dp[x]<<endl;

}