#include <bits/stdc++.h>

using namespace std;

typedef long long int  ll;
const int INF = 1e6 +5;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t;
    while(t--){
        string s; cin>>s;
        int n = s.length();
        int ans = 0;
        vector<int> b;
        b.push_back(-1);
        for(int i = 0; i<n; i++){
            if(s[i]=='B'){
                b.push_back(i);
            }
        }
        b.push_back(n);
        int dp[b.size()+1][2];
        memset(dp, 0, sizeof(dp));
        //0 -> esquerda
        //1 -> direita
        for(int i = 1; i<b.size()-1; i++){
            //cout<<b[i]<<endl;
            dp[i][0] = dp[i-1][0]+((b[i]-b[i-1])-1);
            //cout<<"I: "<<i<<"esq"<<dp[i][0]<<endl;
            dp[i][1] = max(dp[i-1][0], dp[i-1][1])+((b[i+1]-b[i])-1);
            //cout<<"I: "<<i<<"dir"<<dp[i][1]<<endl;

        }
        cout<<max(dp[b.size()-2][0], dp[b.size()-2][1])<<endl;

        

      
    }

    return 0;
}