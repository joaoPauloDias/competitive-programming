#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin>>s;
    int n = s.length();
    bool check = true;
    for(int i = 1; i<=n; i++){
        if(s[i]>=s[i-1]){
            check = false;
            break;
        }
    }

    if(check)cout<<"Yes\n";
    else cout<<"No\n";
}