#include <bits/stdc++.h>

using namespace std;

#define MAXL 5005

int x[MAXL], y[MAXL];

int dist(int p1, int p2){
    return (x[p1]-x[p2])*(x[p1]-x[p2]) + (y[p1]-y[p2])*(y[p1]-y[p2]);
}

int main(){
    int n, ans = 0;
    cin>>n;
    for(int i = 0; i<n; i++)
        cin>>x[i];
    for(int i = 0; i<n; i++)
        cin>>y[i];
    for(int i = 0; i<n; i++)
        for(int j = i+1; j<n; j++)
            ans = max(dist(i, j), ans);

    cout<<ans<<endl;
}

