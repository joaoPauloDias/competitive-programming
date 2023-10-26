#include <bits/stdc++.h>
#define MAXL 500005
//auxilio do tutorial
using namespace std;
int v[MAXL];
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i = 0; i<n; i++)cin>>v[i];

        sort(v, v+n);

        int l = -1, m, r = 1e9;

        while(r - l > 1){
            m = (l+r)/2;
            int i, j;
            for(i = 0; i+1<n; i++){
                if(v[i + 1]-v[0] > 2*m)break;
            }
            for(j = n-1; j - 1>=0; j--){
                if(v[n-1]-v[j-1] > 2*m)break;
            }
            i++; j--;
            if(i>j || v[j]- v[i] <= 2*m){
                r = m;
            }else{
                l = m;
            }
        }
        cout<<r<<endl;
    }
}
