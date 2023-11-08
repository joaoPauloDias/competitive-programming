#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   
    int t; cin>>t;
    while(t--){
        int n, k; cin>>n>>k;
        ll resp  =1;
        for(int i =0 ; i<k; i++){
            resp *= n;
            resp%=mod;
        }
        cout<<resp<<endl;
        
        

    }
    return 0;
}