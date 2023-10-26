#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    int dp[n+1] = {0};
    dp[0] = 1;
    for(int i = 1; i<=n; i++){
        for(int j = i; j>=0; j--){
            dp[i]+=dp[i-j];
        }
    }
    cout<<dp[n]<<endl;
}