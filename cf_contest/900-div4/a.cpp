#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t;
    while(t--){
        int n, k; cin>>n>>k;
        bool ans = false;
        for(int i = 0; i<n; i++){
            int aux;cin>>aux;
            if(aux==k)ans=true;
        }
        if(ans)cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}