#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("peacefulsets.in", "r", stdin);
	//freopen("peacefulsets.out", "w", stdout);

    int n; cin>>n;

    int dp[n+1] = {0};
    
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 2;
    for(int i = 4; i<=n; i++){
        dp[i] = dp[i-1];
        if(3*dp[i]==i)dp[i]++;
    }
    cout<<dp[n]<<endl;

    return 0;
}
