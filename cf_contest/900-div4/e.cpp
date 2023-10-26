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
        int a[n];
        int biggest[n][n];
        memset(biggest, 0, sizeof(biggest));
        for(int i = 0; i<n; i++)cin>>a[i];

        for(int i = 0; i<n; i++){
            int aux = a[i];
            for(int j = i+1; j<n; j++){
                aux &= a[j];
                biggest[i][j] = aux & a[j];
            }
        }
        int q; cin>>q;
        for(int i = 0; i<q; i++){
            int ini, end, alvo, meio;
            cin>>ini>>alvo;
            c = ini;
            
            int id = -1;
            while(ini <=end){
                meio = ini + (fim-ini)/2;
                if(biggest[x])
            }
        }
    }
    
    return 0;
}