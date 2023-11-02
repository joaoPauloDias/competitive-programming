#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

const int INF = 1e9;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin>>n>>m;
    pii start, end;
    int board[n+1][m+1];
    memset(board, 0, sizeof(board));

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            char aux; cin>>aux;
            if(aux=='.')board[i][j] = 1;
            else if(aux=='A'){board[i][j] = 1; start = {i, j};}
            else if(aux=='B'){board[i][j] = 1; end = {i, j};}
        }
    }
    vector<vector<int>> dist(n+5, vector<int>(m+5, INF));
    vector<vector<char>> p(n+5, vector<char>(m+5));
    priority_queue<tiii, vector<tiii>, greater<tiii>> q;
    

    //dist[start.first][start.second] = 0;
    
    q.emplace(0, start.first, start.second);

    while(!q.empty()){
        auto [d, i, j] = q.top();
        q.pop();
        //cout<<':'<<i<<' '<<j<<endl;
        
        if(INF!=dist[i][j])continue;
        dist[i][j] = d;
        if(i == end.first && j == end.second)break;
        if(i+1 <= n && dist[i+1][j]>1+d && board[i+1][j]){
            p[i+1][j] = 'D';
            q.emplace(d+1, i+1, j);
        }
        if(i-1 >=1  && dist[i-1][j]>1+d && board[i-1][j]){
            p[i-1][j] = 'U';
            q.emplace(d+1, i-1, j);
        }
        if(j+1 <= m && dist[i][j+1]>1+d && board[i][j+1]){
            p[i][j+1] = 'R';
            q.emplace(d+1, i, j+1);
        }
        if(j-1 >= 1 && dist[i][j-1]>1+d && board[i][j-1]){
            p[i][j-1] = 'L';
            q.emplace(d+1, i, j-1);
        }
    }

    if(dist[end.first][end.second]==INF){
        cout<<"NO\n";
        return 0;
    }

    cout<<"YES\n";
    int i = end.first, j = end.second;
    vector<char> route;
    while(dist[i][j]!=0){
        //cout<<dist[i][j]<<' '<<i<<' '<<j<<' '<< p[i][j]<<endl;
        route.push_back(p[i][j]);
        if(p[i][j] == 'L')j++;
        else if(p[i][j] == 'R')j--;
        else if(p[i][j] == 'U')i++;
        else if(p[i][j] == 'D')i--;
    }
    cout<<dist[end.first][end.second]<<endl;
    reverse(route.begin(), route.end());
    for(auto c : route){
        cout<<c;
    }
    cout<<endl;
    return 0;
}