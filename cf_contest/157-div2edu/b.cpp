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
        int a[2*n+5];
        for(int i = 0; i<2*n; i++){
            cin>>a[i];
        }
        sort(a, a+2*n);
        vector<pair<int, int>> p(n);
        for(int i = 0; i<n; i++){
            p[i] = {a[i], a[n+i]};
        }
        int sum = 0;
        for(int i = 1; i<n; i++){
            sum+=abs(a[i]-a[i-1]);
            sum+=abs(a[n+i]-a[n+i-1]);
        }
        cout<<sum<<endl;
        for(auto [x, y]: p){
            cout<<x<<' '<<y<<endl;
        }
    }
    return 0;
}