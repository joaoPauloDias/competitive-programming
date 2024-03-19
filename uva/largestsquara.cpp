#include <bits/stdc++.h>

using namespace std;

char g[125][125];
int n, m;

bool check(int ci, int cj, int l){
    if(ci-l<0 || ci+l>=n || cj-l<0 || cj+l>=m)return false;

    for(int i = ci-l; i<=ci+l; i++){
        for(int j = cj-l; j<=cj+l; j++){
            if(g[i][j]!=g[ci][cj])return false;
        }
    }
    
    return true;
}

int main(){

    int t; cin>>t;

    while(t--){
        int q;
        cin>>n>>m>>q;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                cin>>g[i][j];
            }
        }
        cout<<n<<' '<<m<<' '<<q<<endl;
        while(q--){
            int a, b;
            cin>>a>>b;
            int r = 0;
            while(true){
                if(check(a, b, r+1)){
                    r++;
                }else{
                    break;
                }
            }
            cout<<1+2*r<<endl;
        }
    }
}