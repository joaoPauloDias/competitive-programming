#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t;
    while(t--){
        int a, b, c;
        cin>>a>>b>>c;
        int ans = 1e9;
        if(b<=a){
            ans = b+(a-b);
        }else{
            ans = max(0, (b-a-c))+b;
        }
        cout<<ans<<endl;
    }
    
    return 0;
}