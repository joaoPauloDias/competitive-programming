#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 +7;
const int INF = 1e9 +5;
const int MAXL = 1e6+5;

bool possible[MAXL];
int dp[MAXL];

int main(){
    int n, x; cin>>n>>x;
    int w[n+5], s[n+5];


    for(int i = 1; i<=n; i++)cin>>w[i];
    for(int i = 1; i<=n; i++)cin>>s[i];

    possible[0] = true;

    for(int i = 1; i<=n; i++){
        for(int j = x; j>=0; j--){
            if(possible[j]){
                possible[j+w[i]] = true;
                dp[j+w[i]] = max(dp[j+w[i]], dp[j]+s[i]);
            }
        }
    }
    int resp = 0;
    for(int i = 0; i<= x; i++){
        resp = max(resp, dp[i]);
    }
    cout<<resp<<endl;
}