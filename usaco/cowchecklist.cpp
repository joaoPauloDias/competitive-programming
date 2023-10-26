#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxl = 1005;
const ll inf = 1e17;
int h, g;
pair < int, int > ph[maxl];
pair < int, int > pg[maxl];
vector<vector<vector<ll>>> dp(maxl, vector<vector<ll>>(maxl, vector<ll>(2, inf)));

ll dist(pair < int, int > p1, pair < int, int > p2) {
    int x = (p1.first - p2.first);
	int y = (p1.second - p2.second);
	return (x * x) + (y * y);
}

ll min_cost(int hi, int gi, int last) {
    cout<<hi<<' '<<gi<<endl;
    if (dp[hi][gi][last] != -1) return dp[hi][gi][last];
    if (!last) {
        if (hi == h && gi > g) return dist(ph[h], ph[h - 1]);
        ll ch = inf, cg = inf;
        if (hi < h) {
            ch = min_cost(hi + 1, gi, 0) + dist(ph[hi], ph[hi - 1]);
        }
        if (gi <= g) {
            cg = min_cost(hi, gi + 1, 1) + dist(pg[gi], ph[hi - 1]);
        }
        return dp[hi][gi][0] = min(ch, cg);
    } else {
        if (hi == h && gi > g) return dist(ph[h], pg[gi]);
        ll ch = inf, cg = inf;
        if (hi < h) {
            ch = min_cost(hi + 1, gi, 0) + dist(ph[hi], pg[gi - 1]);
        }
        if (gi <= g) {
            cg = min_cost(hi, gi + 1, 1) + dist(pg[gi], pg[gi - 1]);
        }
        return dp[hi][gi][1] = min(ch, cg);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("checklist.in", "r", stdin);
    //freopen("checklist.out", "w", stdout);
    cin >> h >> g;
    //memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= h; i++) cin >> ph[i].first >> ph[i].second;
    for (int i = 1; i <= g; i++) cin >> pg[i].first >> pg[i].second;
    ph[0] = ph[1];
    pg[0] = pg[1];
    dp[1][0][0] = 0;

    for(int hi = 0; hi<=h; hi++){
        for(int gi = 0; gi<=g; gi++){

            if(hi>1){
                dp[hi][gi][0] = min(dp[hi][gi][0], dp[hi-1][gi][0] + dist(ph[hi], ph[hi-1]));
            }
            if(gi>1){
                dp[hi][gi][1] = min(dp[hi][gi][1], dp[hi][gi-1][1] + dist(pg[gi], pg[gi-1]));
            }
            if(hi>0 && gi>0){
                dp[hi][gi][0] = min(dp[hi][gi][0], dp[hi-1][gi][1] + dist(ph[hi], pg[gi]));
                dp[hi][gi][1] = min(dp[hi][gi][1], dp[hi][gi-1][0] + dist(ph[hi], pg[gi]));
            }
            
                  
        }
    }

    cout << dp[h][g][0] << endl;

    return 0;
}