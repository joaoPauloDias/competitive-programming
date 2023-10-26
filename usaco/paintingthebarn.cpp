#include <bits/stdc++.h>
#define MAXL 1005
using namespace std;

int barn[MAXL][MAXL];
int max_x = 1, max_y = 1;
int main(){
    freopen("paintbarn.in", "r", stdin);
	freopen("paintbarn.out", "w", stdout);
    int n, q, ans = 0;
    int x1, y1, x2, y2;
    cin>>n>>q;
    for(int i = 0; i<n; i++){
        cin>>x1>>y1>>x2>>y2;
        barn[++x1][++y1]++;
        barn[++x2][++y2]++;
        barn[x1][y2]--;
        barn[x2][y1]--;
    }

    for(int j = 1; j<MAXL; j++){
        for(int k = 1; k<MAXL; k++){
            barn[j][k] = barn[j-1][k]+barn[j][k-1]+barn[j][k]-barn[j-1][k-1];
            if(barn[j][k]==q)ans++;
        }
    }
    cout<<ans<<endl;
}
