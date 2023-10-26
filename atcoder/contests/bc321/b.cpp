#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, t; cin>>n>>t;
    int s[n];
    for(int i = 0; i<n-1; i++)cin>>s[i];
    
    for(int i = 0; i<=100; i++){
        int aux[n];
        for(int j = 0; j<n-1; j++)aux[j] = s[j];
        aux[n-1] = i;
        sort(aux, aux+n);
        int sum = 0;
        for(int j = 1; j<n-1; j++){
            sum+=aux[j];
        }
        if(sum>=t){
            cout<<i<<endl;
            return 0;
        }
    }

    cout<<-1<<endl;
    return 0;
}