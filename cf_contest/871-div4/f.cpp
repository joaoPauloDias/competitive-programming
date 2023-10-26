#include <bits/stdc++.h>
using namespace std;

int aux[10005];
int main(){

    int t;
    cin>>t;
    while(t--){
        int v, e;
        memset(aux, 0, sizeof(aux));
        cin>>v>>e;
        for(int i =0; i<e; i++){
            int a, b;
            cin>>a>>b;
            aux[a]++;
            aux[b]++;
        }



        int ans[3] = {0}, ans_n[3]={0}, ans_i = 0;
        for(int i = 1; i<=v; i++){

            if(aux[i]!=ans[0]&&aux[i]!=ans[1]&&aux[i]!=ans[2]){
                ans[ans_i] = aux[i];
                ans_i++;
            }
        }

        for(int i = 1; i<=v; i++){
            //cout<<'l'<<aux[i]

            if(aux[i]==ans[0]){
                ans_n[0]++;
            }
            else if(aux[i]==ans[1]){
                ans_n[1]++;
            }
            else{
                ans_n[2]++;
            }
        }
        int xy, x = -1, y = -1, ny;
        for(int i = 0; i < ans_i; i++){
            if(ans[i]==1)xy = ans_n[i];
            if(ans_i == 3 && ans_n[i] == 1)x = ans[i];
            if(ans[i]!=1){y = ans[i];ny = ans_n[i];}
        }
        if(x!=-1){
            cout<<x<<' '<<xy/y<<endl;
        }else{
            cout<<ny-1<<' '<<xy/(ny-1)<<endl;
        }

    }
}
