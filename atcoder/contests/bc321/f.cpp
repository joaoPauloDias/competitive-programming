#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M = 5050;
const ll MOD = 998244353;
int main(){
    ll q, k; cin>>q>>k;
    vector<ll> ways(M);
    ways[0] = 1;

    while(q--){
    char ty; cin >> ty;
    ll v; cin >> v;
    if(ty == '+'){
      for(int i = M - v - 1; i >= 0; i--) ways[i + v] = (ways[i + v]+ways[i])%MOD;
    } else {
      for(int i = 0; i + v < M; i++) ways[i + v] = (ways[i + v] -ways[i])%MOD;
    }
    cout << ways[k]<< "\n";
  }
    
}