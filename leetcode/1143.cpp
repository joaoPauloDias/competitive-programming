#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string a, b;
int dp[1005][1005];
int lcs(int ind_a, int ind_b){
    //pull
    for(int i = 0; i<ind_a; i++){
        for(int j = 0; j<ind_b; j++){
            if(a[i]==b[j])dp[i+1][j+1] =max(dp[i+1][j+1], 1 + dp[i][j]);
            else dp[i+1][j+1] = max({dp[i+1][j+1],dp[i+1][j], dp[i][j+1]});
        }
    }
    /*

    push
    for(int i = 1; i<=ind_a; i++){
        for(int j = 1; j<=ind_b; j++){
            if(a[i]==b[j])dp[i][j] = max(dp[i][j], dp[i-1][j-1]+1);
            else dp[i][j] = max({dp[i][j],dp[i-1][j], dp[i][j-1]});
        }
    }
    */
    return dp[ind_a][ind_b];
    // if(ind_a<0 || ind_b<0){
    //     return 0;
    // }
    // if(dp[ind_a][ind_b]!=-1)return dp[ind_a][ind_b];
    
    // if(a[ind_a]==b[ind_b]){
    //     dp[ind_a][ind_b] = 1 + lcs(ind_a-1, ind_b-1);
    //     return dp[ind_a][ind_b];
    // }
   
    // dp[ind_a][ind_b] = max({lcs(ind_a, ind_b-1), lcs(ind_a-1,ind_b)});
    // return dp[ind_a][ind_b];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>a>>b;
    //a = ' '+a;
    //b = ' '+b;
    memset(dp, 0, sizeof(dp));
    cout<<lcs(a.size(), b.size());
    
    return 0;
}