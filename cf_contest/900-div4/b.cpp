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
        int ini = 1;
        cout<<ini;
        for(int i = 1; i<n; i++){
            ini+=2;
            cout<<' '<<ini;
        }
        cout<<endl;
    }
    
    return 0;
}