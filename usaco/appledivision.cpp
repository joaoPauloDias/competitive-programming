#include <bits/stdc++.h>

using namespace std;

int n, p[25];
long long sum, ans = (int) 20*10e9+5;

void recursao(long long grupo_a, long long grupo_b, int actual){
    if(actual == n)return;
    ans = min(abs(grupo_a - grupo_b), ans);
    recursao(grupo_a-p[actual], grupo_b+p[actual], actual+1);
    recursao(grupo_a, grupo_b, actual+1);
}

int main(){

    cin>>n;

    for(int i = 0; i<n; i++){
        cin>>p[i];
        sum+=p[i];
    }
    recursao(sum, 0, 0);
    cout<<ans<<endl;

}
