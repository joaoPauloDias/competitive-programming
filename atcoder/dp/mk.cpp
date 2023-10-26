#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int h[n+1], dp[n+1][2];
        //0 f
        //1 y
        for(int i = 0; i <n; i++){
            cin>>h[i];
        }
        for(int i = 0; i <n; i++){
            dp[i][0] = dp[i][1] = 1e9;
        }
        
        dp[0][0] = h[0];
        dp[1][0] = h[0]+h[1];
        dp[1][1] = h[0];

        for(int i = 2; i<n; i++){
            dp[i][1] = min(dp[i-1][0], dp[i-2][0]);
            dp[i][0] = h[i]+min(dp[i-1][1], h[i-1]+dp[i-2][1]);
        }

        cout<<min(dp[n-1][0], dp[n-1][1])<<endl;
    }
}