#include <bits/stdc++.h>

using namespace std;
const int INF = 1e6 +5;
int main(){
    int n; 
    cin>>n;
    int p[n+1], v[n+1];
    int p_max = 30;

    for(int i = 1; i<=n;i++){
        p[i] = 1;
        string aux; cin>>v[i]>>aux;
        for(auto j : aux){
            if(j=='A')p[i]*=2;
            else if(j=='B')p[i]*=3;
            else if(j=='C')p[i]*=5;
        } 
    }
    
    vector<int> dp(35, INF);
    dp[1] = 0;

    for(int i = 1; i<=n; i++){
        for(int j = p_max; j>=1; j--){
            if(dp[j]!=INF){
                int aux = gcd(p[i], j);
                if((p[i]*j)/aux<=p_max)
                    dp[(j*p[i])/aux] = min(dp[(j*p[i])/aux], dp[j]+v[i]);
            }
        }
    }

    if(dp[p_max]==INF)dp[p_max]=-1;
    cout<<dp[p_max]<<endl;
}