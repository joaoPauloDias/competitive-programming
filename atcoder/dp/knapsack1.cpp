#include <bits/stdc++.h>
typedef long long int ll;

using namespace std;

int main(){
    int n, c; cin>>n>>c;
    int w[n+1], v[n+1];
    for(int i = 1; i<=n; i++){
        cin>>w[i]>>v[i];
    }
    ll dp[100005] = {0}; 
    bool possible[100005] = {0};
    for(int i = 0; i<100005; i++){
        dp[i] = 1e9;
    }

    dp[0] = 0;
    possible[0] = true;

    for(int i = 1; i<=n; i++){
        for(int j = 100000; j>=0; j--){
            if(possible[j]){
                possible[j+v[i]] = true;
                dp[j+v[i]] = min(dp[j+v[i]], dp[j]+w[i]);
            }
        }
    }

    for(int j = 100000; j>=0; j--){
        if(possible[j] && dp[j]<=c){
            cout<<j<<endl;
            break;
        }  
    }

}