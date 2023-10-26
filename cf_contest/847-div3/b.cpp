#include <bits/stdc++.h>

using namespace std;

int a[55];
int main(){
    int t; cin>>t;

    while(t--){
        int n, s, r;
        cin>>n>>s>>r;
        a[0] = s-r;
        int media = r/(n-1);
        int restantes = s-((media*(n-1)) + a[0]);
        //cout<<restantes<<endl;
        cout<<a[0];
        for(int i = 1; i<n; i++){
            a[i] = media;
            int aux = a[0]-media;
            if(restantes>0){
                if(aux>restantes){
                    a[i]+=restantes;
                    restantes=0;
                }else{
                    a[i]+=aux;
                    restantes-=aux;
                }
            }
            cout<<' '<<a[i];
        }
        cout<<endl;
    }
}
