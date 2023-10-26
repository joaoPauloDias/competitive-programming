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
        int n; cin>>n;
        int v[n];
        int m = INT_MAX, i_m = -1;
        for(int i = 0; i<n; i++){
            cin>>v[i];
            if(v[i]<=m){
                m = v[i];
                i_m = i;
            }
        }
        ll r = 1;
        for(int i = 0; i<n; i++){
            if(i==i_m)r*=(v[i]+1);
            else r*=v[i];
        }
        cout<<r<<endl;
    }

    

    return 0;
}