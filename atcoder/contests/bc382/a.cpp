#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, d;
    string s;
    cin >> n >> d >> s;
    int ans = d;
    for (auto i : s)
    {
        if (i == '.')
            ans++;
    }
    cout << ans << endl;
}