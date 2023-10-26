#include <bits/stdc++.h>
#define MAXL 1004

using namespace std;

map<int, vector<int>> x;
map<int, vector<int>> y;
map<int, vector<int>> dp;
map<int, vector<int>> ds;
char t[MAXL][MAXL];
int dpaux[MAXL][MAXL];
int dsaux[MAXL][MAXL];

int main(){


    int n, resp = 0;
    scanf("%d", &n);


    for(int i = 1; i<=n; i++){dpaux[1][i] = i; dsaux[1][i] = i;}
    for(int i = 2; i<=n; i++){dpaux[i][1] = i+n-1; dsaux[i][n] = i+n-1;}


    for(int i = 1; i<=n; i++)
        for(int j = 1; j<=n; j++){
            scanf(" %c",&t[i][j]);
            if(i!=1 && j!=1 )dpaux[i][j]=dpaux[i-1][j-1];
            if(j<n && i!=1 )dsaux[i][j]=dsaux[i-1][j+1];
            if(t[i][j]=='P'){
                x[i].push_back(j);
                y[j].push_back(i);
                dp[dpaux[i][j]].push_back(i);
                ds[dsaux[i][j]].push_back(i);
            }
        }

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
          if(t[i][j]=='P')continue;
            int sum = 0;
            if(x[i].size()>0){
                if(x[i].front()<j)sum++;
                if(x[i].back()>j)sum++;
            }
            if(y[j].size()>0){
                if(y[j].front()<i)sum++;
                if(y[j].back()>i)sum++;
            }
            if(ds[dsaux[i][j]].size()>0){
                if(ds[dsaux[i][j]].front()<i)sum++;
                if(ds[dsaux[i][j]].back()>i)sum++;
            }
            if(dp[dpaux[i][j]].size()>0){
                if(dp[dpaux[i][j]].front()<i)sum++;
                if(dp[dpaux[i][j]].back()>i)sum++;
            }
            resp=max(resp, sum);

        }
    }
    printf("%d\n", resp);
    return 0;

}
