#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("teamwork.in", "r", stdin);
    freopen("teamwork.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    int dp[n] = {0};
    int c[n];

    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }

    for (int i = 0; i < n; i++)
    {
        int max_c = c[i];
        for (int j = 0; j < k; j++)
        {
            max_c = max(max_c, c[i - j]);
            if (i - j >= 0)
            {
                int max_l = i - j - 1 >= 0 ? dp[i - j - 1] : 0;
                dp[i] = max(dp[i], max_l + (max_c * (j + 1)));
            }
        }
    }

    cout << dp[n - 1] << endl;

    return 0;
}