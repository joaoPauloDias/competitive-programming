#include <bits/stdc++.h>
const int MOD = 1000000007;
const int MAXL = 1000005;

using namespace std;
int memo[MAXL];
int main(){
    int n;
    cin>>n;
    memo[0] = 1;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=6; j++){
            if(i-j>=0){
                memo[i] = (memo[i] + memo[i-j])%MOD;
            }
        }
    }
    cout<<memo[n]<<endl;
}
