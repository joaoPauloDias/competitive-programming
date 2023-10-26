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
        int n, k; cin>>n>>k;
        string s;
        cin>>s;
        int op = 0;
        int aux_k = 0;
        for(int i = 0; i<n; i++){
            aux_k = max(0, aux_k-1);
            if(s[i]=='B'){
                if(aux_k>0)continue;
                aux_k = k;
                op++;
            }
        }
        cout<<op<<endl;
    }
    

    return 0;
}