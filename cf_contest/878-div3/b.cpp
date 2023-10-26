#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k, ans = 0;
        cin>>n>>k;
        int maxl = min(30, k);
        cout<<min(n+1, 1<<maxl)<<endl;
    }
}
