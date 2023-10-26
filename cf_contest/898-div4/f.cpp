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
        int h[n+1], a[n+1];
        ll sum[n+1];
        memset(sum, 0, sizeof(sum));
        for(int i = 1 ; i<=n; i++){
            cin>>a[i];
            sum[i] = sum[i-1]+a[i];
        }
        
        for(int i = 1 ; i<=n; i++)cin>>h[i];
        vector<pair<int,int>> s;
        int ini = 1, end;
        for(int i = 2; i <= n; i++){
            if(h[i-1]%h[i]!=0){
                s.push_back({ini, i-1});
                ini = i;
            }
        }
        s.push_back({ini, n});
        int r = 0;
        //cout<<"inicio"<<endl;
        for(auto p : s){
            //cout<<"par: "<<p.first<<' '<<p.second<<endl;
            ini = p.first, end = p.first;
            //cout<<p.first<<' '<<p.second<<endl;
            ll aux = 0;
            while(ini<=p.second && end<=p.second){
                while(end<=p.second){
                    end++;
                    aux = sum[end]-sum[ini-1];
                    if(aux>k){
                        end--;
                        break;
                    }
                }
                end = min(end, p.second);
                //cout<<"ini: "<<ini<<" end: "<<end<<endl;
                aux = sum[end]-sum[ini-1];
                if(aux<=k)r=max(r, (end-ini)+1);
                ini++;
            }
        }
        cout<<r<<endl;

    }
    

    return 0;
}