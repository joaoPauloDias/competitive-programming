#include <bits/stdc++.h>
#define MAXL 100005
#define f first
#define s second
using namespace std;


int tree[4*MAXL], qr[MAXL];
pair<int, int> seg[MAXL];
int n, m, q;

int sum(int a, int b){
    a+=n; b+=n;
    int s = 0;
    while(a<=b){
        if(a%2==1)s+=tree[a++];
        if(b%2==0)s+=tree[b--];
        a/=2; b/=2;
    }
    return s;
}

void add(int k){
    k+=n;
    tree[k] = 1;
    for( k/=2; k>=1; k/=2){
        tree[k] = tree[2*k]+tree[2*k+1];
    }
}

int main(){
    int t; cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i = 0; i<m; i++){
            cin>>seg[i].f>>seg[i].s;
            seg[i].f--; seg[i].s--;
        }
        cin>>q;
        for(int i = 0; i<q; i++){
            cin>>qr[i];
            qr[i]--;
        }
        int ini = 1, fim = q, meio;
        int r = q+1;
        while(ini<=fim){
            meio = ini + (fim-ini)/2;
            memset(tree, 0, 4*n);
            for(int i = 0; i<meio; i++)
                add(qr[i]);
            bool check = false;
            for(int i = 0; i<m; i++){
                int aux = sum(seg[i].f, seg[i].s);
                if(aux>(1+seg[i].s-seg[i].f)/2){
                    check = true;
                    break;
                }
            }
            if(check){
                fim = meio-1;
                r = min(r, meio);
            }else{
                ini = meio+1;
            }

        }

        if(r>q)r = -1;
        cout<<r;
    }

}
