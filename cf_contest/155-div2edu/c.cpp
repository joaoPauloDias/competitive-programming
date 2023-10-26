#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod = 998244353;
const ll maxl = 1e5*2 + 5;
int main(){
    ll fat[maxl];
    fat[0] = 1;
    fat[1] = 1;
    for(int i = 2; i<maxl; i++)fat[i] = (i*fat[i-1])%mod;

    ll n; cin>>n;
    while(n--){
        string s; cin>>s;
        int l = s.length();
        ll dp[l];
        for(int i = 0; i<l; i++)dp[i] = 1; 
        int aux = 1;
        int r = 0;
        for(int i = 1; i<l; i++){
            dp[i] = dp[i-1];
            if(s[i]==s[i-1]){
                r++;
                aux++;
            }
            if(s[i]!=s[i-1]||i==l-1){
                if(aux>1){dp[i]*=aux;dp[i]%=mod;}

                aux = 1;
            }
        }
        dp[l-1]*=fat[r];
        cout<<r<<' '<<dp[l-1]%mod<<endl;
    }
    
}
