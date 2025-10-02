#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; cin>>t;

    while(t--){
        int n,m,x,y; cin>>n>>m>>x>>y;
        int x_rays[m], y_rays[n];
        for(int i=0; i<n; i++){cin>>y_rays[i];}
        for(int i=0; i<m; i++){cin>>x_rays[i];}
        int crossing=   0;
        for(int i=0; i<m; i++){
            if(x_rays[i]<x) crossing++;
        }
        for(int i=0; i<n; i++){
            if(y_rays[i]<y) crossing++;
        }
        cout<<crossing<<endl;
    }
}