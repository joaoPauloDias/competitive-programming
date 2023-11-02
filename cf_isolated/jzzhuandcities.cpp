#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair < int, int > ;
using tiii = tuple < ll, ll, int > ;

const ll INF = 1e18;
const int MAXN = 1e5 + 50;

bool used[MAXN];
int total[MAXN];
int ans;

vector < vector < tiii >> adj(MAXN, vector < tiii > ());
priority_queue < tiii, vector < tiii > , greater < tiii >> q;
vector < ll > d(MAXN, INF);
vector < pii > r;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    while (m--) {
        int u, v, x;
        cin >> u >> v >> x;
        adj[u].emplace_back(v, x, 0);
        adj[v].emplace_back(u, x, 0);
    }

    while (k--) {
        int s, y;
        cin >> s >> y;
        adj[1].emplace_back(s, y, 1);
        adj[s].emplace_back(1, y, 1);
        r.emplace_back(s, y);
    }

    q.emplace(0, 0, 1);

    while (!q.empty()) {
        auto[d_v, t_v, v] = q.top();
        q.pop();
        if (INF != d[v])
            continue;
        used[v] = t_v;
        d[v] = d_v;
        for (auto[u, len, t_u]: adj[v]) {
            ll d_u = d_v + len;
            if (d_u < d[u]) {
                q.emplace(d_u, t_u, u);
            }
        }
    }

    for (auto[s, y]: r) {
        if (y > d[s]) ans++;
        else {
            if (used[s] == 0) ans++;
            else ans+=(++total[s])>1;
        }
    }
    
    cout << ans << endl;
}