#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n; string aux;
        cin>>n>>aux;
        for(int i = 0; i < n; i++){
            char atual = aux[i];
            cout<<aux[i];
            for(int j = i+1; j<n; j++){
                if(aux[j] == aux[i]){
                    i = j;
                    break;
                }
            }
        }
        cout<<endl;
    }
}
