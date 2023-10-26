#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 +7;
const int INF = 1e9 +5;

int main(){

    int n; cin>>n;
    vector<int> dp(n+1, 1e9+5);
    bool possible[n+1] = {false};
    possible[n] = true;
    dp[n] = 0;
    for(int i = n; i>=0; i--){
        if(possible[i]){
            int aux = i;
            while(aux>0){
                int resto = aux%10;
                aux/=10;
                if(i-resto>=0){
                    possible[i-resto]=true;
                    dp[i-resto] = min(dp[i-resto], dp[i]+1);
                }
            }
        }
    }
    cout<<dp[0]<<endl;
   
}