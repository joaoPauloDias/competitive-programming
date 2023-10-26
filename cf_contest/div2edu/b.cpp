
#include <bits/stdc++.h>

using namespace std;


int main(){
    int t; cin>>t;

    while(t--){
        int n, k;
        cin>>n>>k;
        int v[n+1];
        pair<int,int> aux[n+1];
        for(int i = 0; i<n; i++){
            cin>>v[i];
            aux[i].second =  i;
            aux[i].first = -(v[i] - ((ceil(double(v[i])/double(k))-1)*k));
            //cout<<aux[i].first<<' '<<aux[i].second.first<<' '<<aux[i].second.second<<endl;
        }
        sort(aux, aux+n);
        for(int i = 0; i<n; i++){
            cout<<1+aux[i].second<<' ';
        }
        cout<<endl;

    }

}
