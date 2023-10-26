#include <bits/stdc++.h>

using namespace std;


int main(){
    int t; cin>>t;

    while(t--){
        int n, m;
        string s;
        cin>>n>>m>>s;
        int ch[n], z[n];
        int r =0;
        bool check = false;
        pair<int, int> q[m];
        set<pair<int,int>>auxs;
        ch[0] = 0;
        z[0] = s[0]=='0';
        for(int i = 1; i<s.length(); i++){
            z[i]=z[i-1]+(s[i]=='0');
            ch[i]=ch[i-1]+(ch[i]!=ch[i-1]);
        }
        for(int i = 0; i<m; i++)cin>>q[i].first>>q[i].second;
        sort(q, q+m);
        for(int i = 0; i<m; i++){
            int a = q[i].first-1, b = q[i].second-1;
            if(z[a]!=z[b] && ch[a]!=ch[b]){
                auxs.insert(make_pair(z[a],z[b]));
            }else{
                check=true;
            }
        }


        cout<<auxs.size()+check<<endl;

    }

}
