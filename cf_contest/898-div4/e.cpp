#include <bits/stdc++.h>

using namespace std;

typedef long long int  ll;
const int INF = 1e6 +5;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin>> t;
    while(t--){
        int n, k; cin>>n>>k;
        int c[n];
        for(int i = 0; i<n; i++)cin>>c[i];

        ll ini = 0, end = 1e10, meio;
        ll r = -1;
        while(ini<=end){
            meio = ini + (end-ini)/2;
            ll aux = 0;
            for(int i  = 0; i <n; i++){
                if(c[i]>=meio)continue;
                aux+=meio-c[i];
            }

            if(aux>k){
                end = meio-1;
            }
            if(aux<=k){
                r = max(r, meio);
                ini = meio+1;
            }
        }
        cout<<r<<endl;
    }

    return 0;
}