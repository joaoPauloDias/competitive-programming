#include <bits/stdc++.h>
#define MAXL 100005
using namespace std;

int v[MAXL];
int main(){
    int t;
    cin>>t;
    while(t--){
        int n, maxr = 0, maxl, ans = 0;
        cin>>n>>v[0];
        maxl = v[0];
        for(int i = 1; i<n; i++){
            cin>>v[i];
            if(v[i]<v[i-1]){
                maxr = max(maxr, maxl-v[i]);
            }else{
                maxl = max(maxl, v[i]);
            }

        }
        cout<<"-m"<<maxr<<endl;
        for(int i = 30; i>= 0; i--){
            if(maxr & (1<<i)){
                ans = i;
                for(int j = i-1; j>=0; j--){
                    if(maxr & (1<<j)){
                        ans++;
                        break;
                    }
                }
                break;
            }
        }
        cout<<ans<<endl;
    }

}

