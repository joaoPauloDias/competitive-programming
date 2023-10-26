#include <bits/stdc++.h>
#define MAXL 200005
using namespace std;


const int INF = 2e9;
int a[MAXL];
int mem[MAXL][2];
int f_n;

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>f_n;
        for(int i = 0; i<f_n; i++){
            cin>>a[i];
            mem[i][0] = INF;
            mem[i][1] = INF;

        }

        mem[0][0] = a[0];
        mem[1][1] = a[0];
        mem[1][0] = a[0]+a[1];

        for(int i = 2; i < f_n; i++){
            mem[i][0] = min(mem[i-1][1] + a[i], mem[i-2][1]+a[i-1]+a[i]);
            mem[i][1] = min(mem[i-1][0], mem[i-2][0]);
        }
        cout<<min(mem[f_n-1][0], mem[f_n-1][1])<<endl;


    }

}


/*
solução recursiva:

int a[MAXL];
int mem[MAXL][2];
bool ready[MAXL][2];
int f_n;

int calc(int atual, int jogador){
    if(ready[atual][jogador])return mem[atual][jogador];
    if(atual>=f_n)return 0;
    int best = MAXL;
    if(jogador == 0){
         best = min(best, a[atual]+calc(atual+1, !jogador));
         best = min(best, a[atual]+a[atual+1]+calc(atual+2, !jogador));
    }else{
        best = min(best, min(calc(atual+1, !jogador), calc(atual+2, !jogador)));
    }
    mem[atual][jogador] = best;
    ready[atual][jogador] = true;
    return mem[atual][jogador];
}
int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>f_n;
        memset(ready, false, sizeof(ready));
        for(int i = 0; i<f_n; i++)
            cin>>a[i];
        cout<<calc(0, 0)<<endl;


    }

}
*/
