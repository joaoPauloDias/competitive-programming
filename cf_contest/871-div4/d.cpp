#include <bits/stdc++.h>

using namespace std;

bool check(int n, int m){
    if(n==m) return true;
    if(n%3 || m>n) return false;
    int aux = n/3;
    if(aux==m || aux*2 == m) return true;
    return check(aux, m) || check(aux*2, m);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        if(check(n,m))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
