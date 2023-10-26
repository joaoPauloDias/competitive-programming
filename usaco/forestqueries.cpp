#include <bits/stdc++.h>
#define MAXN 1005
using namespace std;

int a[MAXN][MAXN];
int s[MAXN][MAXN];
int s2[MAXN][MAXN];

int main()
{
    int n, q, actual;
    char aux;
    cin>>n>>q;

    for(int i = 1; i <=n ; i++)
        for(int j = 1; j <= n ; j++)
        {
            cin>>aux;
            actual = (aux=='.') ? 0 : 1;
            s[i][j] = s[i][j-1] + s[i-1][j] - s[i-1][j-1] + actual;
        }

    for(int i = 0; i<q; i++){
        int y1, x1, y2, x2;
        cin>>y1>>x1>>y2>>x2;
        int r = s[y2][x2] - (s[y1-1][x2] + s[y2][x1-1] - s[y1-1][x1-1]);
        cout<<r<<endl;
    }





}

