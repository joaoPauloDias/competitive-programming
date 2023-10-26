#include <bits/stdc++.h>

using namespace std;

#define MAXL 1501
//int  l = (1+double(sqrt(8.0*10e6)))/2;

unsigned long long int memo[MAXL][MAXL], aux;
//unsigned long long int aux;
unsigned long long int resp[(int)10e6+100];
int main(){
    int t;

    for(int i = 1; i<MAXL; i++){
        for(int j = 1; j<MAXL; j++){
            aux = (j==1) ? memo[i-1][j]+i-1 : memo[i][j-1]+(j+i-1);
            memo[i][j] = max((unsigned long long int) 1, aux);
        }
    }

    for(int i = 1; i<MAXL; i++){
        for(int j = 1; j<MAXL; j++){
            aux =  memo[i][j];
            memo[i][j] = memo[i][j]*memo[i][j] + memo[i][j-1]+memo[i-1][j]-memo[i-1][j-1];
            resp[(int)aux] = memo[i][j];
        }
    }

    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<resp[n]<<endl;
    }
}
