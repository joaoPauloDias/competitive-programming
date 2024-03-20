// https://codeforces.com/problemset/problem/1006/F

#include <bits/stdc++.h>

using ll = long long;
int n, m, k;

int obj;
vector<vector<ll>> g(25, vector<ll>(25, 0));
vector<vector<map<ll, int>>> vals(25, vector < vector<map<ll, int>>(25));

void left(int nivel, int i, int j, int val)
{
    if (nivel == obj)
    {
        vals[i][j][val]++;
        return;
    }
    if (i + 1 < n)
        left(nivel + 1, i + 1, j, val ^ g[i][j]);
    if (j + 1 < m)
        left(nivel + 1, i, j + 1, val ^ g[i][j]);
}

int main()
{
    cin >> n >> m >> k;
    // obj = (n - 1) / 2 + (m - 1) / 2;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> g[i];
        }
    }
    obj = n;
    left(1, 0, 0, g[0][0]);
}