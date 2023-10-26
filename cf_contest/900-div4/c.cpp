#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 
    while(t--){
        ll n, k, x;
        cin>>n>>k>>x;
        int aux = 1;
     
        ll sum = (1+k)*k/2;
        ll sum2 = (n-k+1 + n)*k/2;
        
        if(sum<=x && sum2>=x ){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }

    }
    return 0;
}