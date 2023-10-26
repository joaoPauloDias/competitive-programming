#include <bits/stdc++.h>
#define MAXS 2147483647
using namespace std;

vector<array<int, 2>> quadrados;
vector<array<int, 3>> duplas;
vector<array<int, 4>> triplas;
map<int, bool> frq;
map<int, int> val;


bool comp(array<int, 4> s1, array<int, 4> s2){
    return s1[0]<s2[0];
}


int main(){
    int n; cin>>n;
     for(int i = 0; i<220; i++){
        unsigned long long int aux = i*i*i*i;
        if(aux>MAXS)break;
        quadrados.push_back({(int)aux, i});
        frq[aux] = true;
        val[aux] = i;
    }

    for(int i = 0; i<quadrados.size(); i++){
        for(int j = i; j<quadrados.size(); j++){
            unsigned long long int aux = quadrados[i][0]+quadrados[j][0];
            if(aux>MAXS)
                break;
            duplas.push_back({(int)aux, quadrados[i][1], quadrados[j][1]});
        }
    }

    for(int i = 0; i<duplas.size(); i++){
        for(int j = 0; j<quadrados.size(); j++){
            if(quadrados[j][1]<duplas[i][2])continue;
            unsigned long long int aux = duplas[i][0]+quadrados[j][0];
            if(aux>MAXS)
                break;
            triplas.push_back({(int)aux, duplas[i][1], duplas[i][2], quadrados[j][1]});
        }
    }

    sort(triplas.begin(), triplas.end(), comp);
    //cout<<triplas.size()<<endl;
    for(int i = 0; i<n; i++){
        int r; cin>>r;
        vector<array<int,4>>resp;
        for(int i = 0; i<triplas.size(); i++){
            if(triplas[i][0]>r)break;
            //cout<<triplas[i].first<<endl;
            int aux = r-triplas[i][0];
            if(frq[aux]==true && val[aux]>=triplas[i][3]){
                resp.push_back({triplas[i][1], triplas[i][2], triplas[i][3], val[aux]});
            }
        }
        if(resp.size() == 0)cout<<0<<endl;
        else{
            cout<<resp.size()<<endl;
            for(auto v:resp){
                cout<<v[0]<<' '<<v[1]<<' '<<v[2]<<' '<<v[3]<<endl;
            }
        }
    }

}
