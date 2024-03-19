#include <bits/stdc++.h>

using namespace std;

int penta[1000005];
int sums[11][1000005];

void sieve(){
    for(int i = 2; i<1000005; i++){
        if(penta[i]==0){
            for(int j = i; j<1000005; j+=i){
                penta[j]++;
            }
        }
    }
}

int main(){
    sieve();
    for(int i = 0; i <= 10; i++){
        for(int j = 1; j<1000005; j++){
            sums[i][j] = sums[i][j-1] + (penta[j]==i);
        }
    }
    int t; cin>>t;  
    while(t--){
        int a, b, k;
        cin>>a>>b>>k;
        cout<<sums[k][b]-sums[k][a-1]<<endl;
    }
   
    return 0;

}