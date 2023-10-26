#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int a[n], b[n];
        for(int i =0 ; i<n; i++)cin>>a[i];
        b[0] = 1;
        if(a[0]==b[0])b[0] = 2;
    
        for(int i =1; i<n; i++){
            b[i] = b[i-1]+1;
            if(b[i]==a[i]){
                b[i] = a[i]+1;
            }
        }
        cout<<b[n-1]<<endl;
    }
    return 0;
}