#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin>>t;
    int i = 0;
    while(t--){
        i++;
        int s, d, k;
        cin>>s>>d>>k;
        int buns, burgers;
        buns = 2*(s + d);
        burgers = s+ 2*d;
        bool check = k<=burgers && (k+1)<=buns;
        cout<<"Case #"<<i<<": ";
        if(check)cout<<"YES\n";
        else cout<<"NO\n";
    }
}