#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


const int inf = 1e9 + 7;

struct coord{
    int x;
    int y;
};


int dist(coord c1, coord c2){
    int x = c1.x-c2.x;
    int y = c1.y-c2.y;
    return (x*x) + (y*y); 
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("radio.in", "r", stdin);
    freopen("radio.out", "w", stdout);

    int n, m; cin>>n>>m;
    coord pn[n+5], pm[m+5];

    cin>>pn[0].x>>pn[0].y;
    cin>>pm[0].x>>pm[0].y;

    string cn, cm;
    cin>>cn>>cm;
    
    for(int i = 0; i<n; i++){
        pn[i+1] = pn[i];
        if(cn[i]=='N')pn[i+1].y+=1;
        if(cn[i]=='S')pn[i+1].y-=1;
        if(cn[i]=='W')pn[i+1].x-=1;
        if(cn[i]=='E')pn[i+1].x+=1;
    }

    for(int i = 0; i<m; i++){
        pm[i+1] = pm[i];
        if(cm[i]=='N')pm[i+1].y+=1;
        if(cm[i]=='S')pm[i+1].y-=1;
        if(cm[i]=='W')pm[i+1].x-=1;
        if(cm[i]=='E')pm[i+1].x+=1;
    }

    vector<vector<int>> dp(n+5, vector<int>(m+5, inf)); 
    
    dp[0][0] = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            dp[i+1][j] = min(dp[i+1][j], dp[i][j] + dist(pn[i+1], pm[j]));
            dp[i][j+1] = min(dp[i][j+1], dp[i][j] + dist(pn[i], pm[j+1]));
            dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j] + dist(pn[i+1], pm[j+1]));
        }
    }
    cout<<dp[n][m]<<endl;
    return 0;
}