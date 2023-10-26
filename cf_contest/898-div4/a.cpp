#include <bits/stdc++.h>

using namespace std;

typedef long long int  ll;
const int INF = 1e6 +5;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t;
    while(t--){
        string a; cin>>a;
        string b= "abc";
        int s = 0;
        for(int i = 0; i <3;i++){
            if(b[i]==a[i])s++;
        }
        if(s==0)cout<<"NO\n";
        else cout<<"YES\n";
    }

    

    return 0;
}