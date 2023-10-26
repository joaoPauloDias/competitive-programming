#include <bits/stdc++.h>

using namespace std;

int main(){
    int v1, v2;
    int t, d;
    cin>>v1>>v2>>t>>d;
    int dp[t+5][5000];
    memset(dp, 0, sizeof(dp));
    dp[0][v1] = v1;
    for(int i = 0; i<t; i++){
        for(int j = 0; j<1000; j++){
            for(int k = -d; k<=d; k++){
                if(j+k>=0 && dp[i][j]>0)dp[i+1][j+k] = max(dp[i+1][j+k], dp[i][j]+(j+k));
            }
        }
    }

    cout<<dp[t-1][v2]<<endl;
}