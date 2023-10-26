#include <bits/stdc++.h>
#define MAXL 1005
#define ull unsigned long long int
using namespace std;


int main(){
    ull n; cin>>n;
    ull resp = n+1, aux = 2*n;
    for(int i = 2; i<=n; i++)
        resp = lcm(resp, n+i);
    cout<<resp<<endl;
}
