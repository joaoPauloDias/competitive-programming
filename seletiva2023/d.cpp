#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int main(){
    int n, m; cin>>n>>m;
    ll v[n];
    for(int i = 0; i<n; i++)cin>>v[i];
    while(m--){
        ll b;
        cin>>b;
        ll aux = v[0]+b;
        for(int i = 1; i<n; i++){
            aux = abs(__gcd(v[i]+b - aux, aux));
            //cout<<aux<<endl;
        }

        cout<<aux<<endl;
    }
}
