#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t;
    while(t--){
        int n; cin>>n; 
        int r; cin>>r;
        for(int i = 1; i<n; i++){
            int aux; cin>>aux;
            r&=aux;
        }
        cout<<r<<endl;
    }
    
    return 0;
}