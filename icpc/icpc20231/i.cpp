#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;

int r, c; 
int m[150][150];
bool vis[150][150];
int best = 0;
int bfs(int i, int j) {
    priority_queue<pair<int, pair<int, int>>> nodes;
    nodes.push({-m[i][j], {i, j}});
    int acc = 0;
    int threshold = m[i][j]-1;
    while (!nodes.empty()) {
        auto k = nodes.top();
        nodes.pop();

        // cout << "k: " << m[k.s.f][k.s.s] << " == " << k.f << endl;
        if (vis[k.s.f][k.s.s]) continue;
        vis[k.s.f][k.s.s] = true;
        if (m[k.s.f][k.s.s] <= threshold) continue;
        threshold = m[k.s.f][k.s.s];

        //cout << "k*: " << m[k.s.f][k.s.s] << endl;

        acc++;

        int ii = k.s.f, jj = k.s.s;
        if(ii+1<r && !vis[ii+1][jj]){
            //cerr << "+1 0" << " [" << m[ii+1][jj] << "]" << endl;
            //cerr << "(" << ii+1 << ", " << jj << ")" << endl;
            nodes.push({-m[ii+1][jj], {ii+1, jj}});
        }
        if(ii-1>=0 && !vis[ii-1][jj]) {
            //cerr << "-1 0" << " [" << m[ii-1][jj] << "]" << endl;
            nodes.push({-m[ii-1][jj], {ii-1, jj}});
        }
        if(jj+1<c && !vis[ii][jj+1]){
            //cerr << "0 +1" << " [" << m[ii][jj+1] << "]" << endl;
            nodes.push({-m[ii][jj+1], {ii, jj+1}});
        }
        if(jj-1>=0 && !vis[ii][jj-1]){
            //cerr << "0 -1" << " [" << m[ii][jj-1] << "]" << endl;
            nodes.push({-m[ii][jj-1], {ii, jj-1}});
        }
    }
    return acc;
}

// 1 5 2
// 3 4 6

// 1 5
// 2 3
// 4 6

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>r>>c;
    
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> m[i][j];
        }
    }
    
    for(int i = 0; i<r; i++){
        for(int j = 0; j<c;j++){
            // cout<<m[i][j]<<' ';
        }
        // cout<<endl;
    }

#define debug_var(x) #x " = " << x
    // cerr << debug_var(r) << " - " << debug_var(c) << endl;

    for(int i = 0; i<r; i++)
        for(int j = 0; j<c;j++){
            //zera vis
            if(m[i][j] > (r*c)-best) continue;
            memset(vis, false, sizeof(vis));
            
            int res = bfs(i,j);
            // cerr << "bfs(" << i << ", " << j << ") = " << res << endl << endl;
            best = max(best, res);
        }
    
    
    cout << best << endl;
    return 0;
}
