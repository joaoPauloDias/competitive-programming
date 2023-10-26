#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
using namespace std;

int modpow(int a, int b, int mod){
    if(b == 0) return 1;
    ll u = modpow(a,b/2, mod);
    u = (u*u)%mod; //a^b se par e a^b-1 se impar
    if(!(b % 2))return u;
    return (a*u)%mod;
}

int main(){
    int t; cin>> t;
    while(t--){
        int a, b;
        cin>>a>>b;
        cout<<modpow(a, b, MOD)<<endl;

    }

}
