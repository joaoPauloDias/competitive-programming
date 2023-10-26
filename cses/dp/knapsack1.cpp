#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, e;
    cin >> n >> k >> e;

    int L = e, R = n - k - e;
    bool dp[L + 1][R + 1];

    memset(dp, false, sizeof(dp));
    dp[0][0] = 1;

    for (int i = 0; i <= n; i++) {
        if (i == k) continue;
        for (int l = L; l >= 0; l--) {
            for (int r = R; r >= 0; r--) {
                if (r + i <= R) dp[l][r + i] |= dp[l][r];
                if (l + i <= L) dp[l + i][r] |= dp[l][r];
            }
        }
    }

    for (int l = L; l >= 0; l--) {
        for (int r = R; r >= 0; r--) {
            if (dp[l][r]) {
                cout << n - k - r - l << endl;
                return 0;
            }
        }
    }
    
}