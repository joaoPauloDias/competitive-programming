#include <bits/stdc++.h>

using namespace std;

int s[200005];
int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k, q, len = 0;
        unsigned long long int ans = 0;
        cin>>n>>k>>q;
        for(int i = 0; i<n; i++){
            cin>>s[i];
            if(s[i]<=q){
                len++;
                if(len>=k){
                    ans++;
                    ans+=max(0, len-k);
                }
            }else{len = 0;}
        }
        cout<<ans<<endl;
    }
}
