#include <bits/stdc++.h>
#define ull unsigned long long
#define MAXL 100000
#define MOD 1000000007
using namespace std;

ull res[MAXL+100], resc[MAXL+100];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, k, a, b;
    cin>>t>>k;

    for(int i = 1; i<= MAXL; i++){
        res[i] = 1;
        for(int j = 1; j<=i/k; j++)
            res[i]+=(i-(j*k)+1)%MOD;

        resc[i] = (res[i]+resc[i-1])%MOD;
    }
    while(t--){
        cin>>a>>b;
        ull ans = ((resc[b]%MOD-resc[a-1]%MOD)%MOD);
        cout<<ans<<endl;
    }
    return 0;

}
