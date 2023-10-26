#include <bits/stdc++.h>

typedef long long int ll;
using namespace std;

int main(){
   int n; cin>>n;
   int d[n][3];
   for(int i = 0; i <n; i++){
    cin>>d[i][0]>>d[i][1]>>d[i][2];
   }
   ll dp[n][3];
   memset(dp, 0, sizeof(dp));
   dp[0][0] = d[0][0];
   dp[0][1] = d[0][1];
   dp[0][2] = d[0][2];
   for(int i = 1; i <n; i++){
        dp[i][0] = d[i][0] + max(dp[i-1][1], dp[i-1][2]);
        dp[i][1] = d[i][1] + max(dp[i-1][0], dp[i-1][2]);
        dp[i][2] = d[i][2] + max(dp[i-1][0], dp[i-1][1]);
   }

   cout<<max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2]))<<endl;
}