#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
int main(){
    ll n, m, p;
    cin>>n>>m>>p;
    ll a[n], b[m];
    ll s_a[n], s_b[m];
    for(int i = 0; i<n; i++)cin>>a[i];
    sort(a, a+n);
    s_a[0] = a[0];
    for(int i = 1; i<n; i++)s_a[i] = s_a[i-1]+a[i];

    for(int i = 0; i<m; i++)cin>>b[i];
    sort(b, b+m);
    s_b[0] = b[0];
    for(int i = 1; i<m; i++)s_b[i] = s_b[i-1]+b[i];

    int lim = m-1;
    ll sum = 0;
    for(int i = 0; i<n; i++){
        for(int j = lim; j>=0; j--){
            if(a[i]+b[j]<p){
                lim = j;
                break;
            }
        }
        if(a[i]+b[0]>=p){
            lim = -1;
        }
        if(lim == -1){
            sum+=p*m;
        }else{
            //cout<<"valor: "<<a[i]<<" Lim: "<<lim<<endl;
            //cout<<"s_b[lim]: "<<s_b[lim]<<" resto Lim: "<<(m-lim)<<endl;
            sum += (s_b[lim]+(lim+1)*a[i]) + (m-lim-1)*p;
        }
    }
    cout<<sum<<endl;

}