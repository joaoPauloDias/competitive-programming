#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long int
#define MAXL 100005
int n;
ull k, resp = 2*1e18;
int a[MAXL], b[MAXL];

void buscab(){
    ull ini = 1, fim = 2*1e18, meio;
    ull banco;
    while(ini<=fim){
        bool flag = true;
        meio = ini+ (fim - ini)/2;
        banco = 0;

        for(int i = 0; i <n; i++){
            if(meio<a[i]){
                flag=false;
                break;
            }
             banco+=1+((meio-a[i])/b[i]);
        }

        if(banco>=k && flag){
            //cout<<banco<<' '<<meio<<endl;
            resp = min(resp, meio);
            fim = meio - 1;
        }else{
            ini = meio + 1;
        }
    }
}


int main(){
    cin>>n>>k;
    for(int i = 0; i<n; i++){
        cin>>a[i]>>b[i];
    }
    buscab();
    cout<<resp<<endl;
}
