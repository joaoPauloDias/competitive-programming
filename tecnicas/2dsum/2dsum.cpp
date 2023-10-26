#include <bits/stdc++.h>
#define MAXN 1005
using namespace std;

int a[MAXN][MAXN];
int s[MAXN][MAXN];
int s2[MAXN][MAXN];

int main()
{
    int n, aux;
    cin>>n;
    for(int i = 1; i <=n ; i++)
    {
        for(int j = 1; j <= n ; j++)
        {
            cin>>a[i][j];
            s[i][j] = s[i][j-1] + a[i][j];
        }
    }

    for(int i = 1; i <=n ; i++)
    {
        for(int j = 1; j <= n ; j++)
        {
            s[i][j] += s[i-1][j];
        }
    }

    cout<<endl;

    for(int i = 1; i <=n ; i++)
    {
        for(int j = 1; j <= n ; j++)
        {
            cout<<a[i][j]<<' ';
        }
        cout<<endl;
    }
    cout<<endl;

    for(int i = 1; i <=n ; i++)
    {
        for(int j = 1; j <= n ; j++)
        {
            cout<<s[i][j]<<' ';
        }
        cout<<endl;
    }
    cout<<endl;


}
