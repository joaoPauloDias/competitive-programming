#include<bits/stdc++.h>
#define MOD 1000000007
#define MAXN 105
using namespace std;

typedef long long ll;

ll dp[MAXN][2];
bool calc[MAXN][2];
int n, k, d;

int cdp(int target, bool check)
{
    if(calc[target][check])return dp[target][check];
    calc[target][check] = true;

    for(int i = 1; i<= k; i++)
    {
        if(target-i>=0)
        {
            dp[target][check] = (dp[target][check] + cdp(target-i, check | i>=d))%MOD;
        }
    }
    return dp[target][check];
}


int main()
{

    cin>>n>>k>>d;

    dp[0][true] = 1;
    dp[0][false] = 0;

    cdp(n, false);//54 60 16

    cout<<dp[n][true]--<<endl;


}
