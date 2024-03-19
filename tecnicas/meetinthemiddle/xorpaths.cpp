// https://codeforces.com/problemset/problem/1006/F

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

ll n, m, k;
ll obj;
ll r = 0;
vector<vector<ll>> g(25, vector<ll>(25, 0));
vector<vector<map<ll, int>>> vl(25, vector<map<ll, int>>(25));

void left(int nivel, int i, int j, ll val)
{
    if (nivel == obj)
    {
        vl[i][j][val ^ g[i][j]]++;
        return;
    }
    if (i + 1 < n)
        left(nivel + 1, i + 1, j, val ^ g[i][j]);
    if (j + 1 < m)
        left(nivel + 1, i, j + 1, val ^ g[i][j]);
}

void right(int nivel, int i, int j, ll val)
{
    if (nivel == obj)
    {
        if(vl[i][j].count(k^val))
            r+=vl[i][j][k^val];
        return;
    }
    if (i - 1 >= 0)
        right(nivel + 1, i - 1, j, val ^ g[i][j]);
    if (j - 1 >= 0)
        right(nivel + 1, i, j - 1, val ^ g[i][j]);
}

int main()
{
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> g[i][j];
        }
    }

    obj = (n+m-2)/2;
    left(0, 0, 0, 0);
    obj = n+m -2 -obj;
    right(0, n - 1, m - 1, 0);

    //if(n==m && n==1)r = g[0][0]==k;
    cout<<r<<endl;
}