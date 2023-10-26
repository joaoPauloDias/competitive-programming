#include <bits/stdc++.h>
#define MAXL 500005
using namespace std;

string g;
string vp[MAXL];
vector<pair<string, int>> s;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, p;
    cin>>n>>p;
    for(int i = 0; i<p; i++)cin>>vp[i];
    cin>>g;
    int ini = 0;

    while(ini<n){
        int ls = -1; int is; string ss;
        for(int i = 0; i<p; i++){
            int j = ini;
            while(ini<n){
                if(vp[i][j]==g[j])
                    j++;
                else break;
            }
            if(j-ini > ls){
                ls = j-ini;
                is = i;
            }
        }
        if(ls < 1){
            ss+=g[ini];
            s.push_back(make_pair(ss, -1));
            ini++;
        }else{
            ss = g.substr(ini, ls);
            s.push_back(make_pair(ss, is+1));
            ini+=ls;
        }
    }

    for(auto i : s){
        cout<< i.first<<' '<<i.second<<'\n';
    }

}
