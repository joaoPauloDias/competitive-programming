#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
int main(){
    int n, k; cin>>n>>k;
    int w[n+1];
    int b[n+1];
    for(int i = 1; i<=n; i++)cin>>w[i];

    for(int i = 1; i<=n; i++)cin>>b[i];

    ll t_s[n+1] = {0}, b_s[n+1] = {0};
    for(int i = 1; i<=n; i++){
        t_s[i] = t_s[i-1]+(w[i]*(!b[i]));
        b_s[i] = b_s[i-1]+(w[i]*b[i]);
    }
    ll resp = 0;
    for(int i = 0; i<=n; i++){
        //cout<< t_s[min(n, i+k)]-t_s[i] <<endl;
        resp = max(resp, t_s[min(n, i+k)]-t_s[i]);
    }
    cout<<resp+b_s[n]<<endl;
}