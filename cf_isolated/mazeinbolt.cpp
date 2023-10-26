#include <bits/stdc++.h>
#include <cstring>
#include <queue>
#include <sstream>
#include <string>

using namespace std;

#define range(x, l, u) (long long x = (l); x < (u); x++)
#define let auto
#define debug_var(x) #x " = " << (x)

int c, r;
bool key[105];
bool maze[1005][105];
bool visited[1005][105];

void flip_nut() {
    for range(j, 0, c>>1) {
        auto temp = key[j];
        key[j] = key[c-j-1];
        key[c-j-1] = temp;
    }
}

bool check_match(long long offset, long long layer) {
    for range(j, 0, c) {
        if (key[(j+offset) % c] && maze[layer][j]) {
            return false;
        }
    }
    return true;
}

bool solve_maze() {
    priority_queue<pair<int, int>> queue;

    for range(c_off, 0, c) {
        queue.push({0, c_off});
    }

    while (!queue.empty()) {
        auto item = queue.top();
        queue.pop();
        int i = item.first;
        int j = item.second;

        if (visited[i][j]) continue;
        visited[i][j] = true;

        if (!check_match(j, i)) continue;

        cerr << "(" << i << ", " << j << ")" << endl;

        if (i == r-1) return true;

        queue.push({(max(0, i-1)), (c+j  ) % c});
        queue.push({(r+i+1) % r, (c+j  ) % c});
        queue.push({(r+i  ) % r, (c+j-1) % c});
        queue.push({(r+i  ) % r, (c+j+1) % c});
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    getline(cin, s);
    istringstream iss(s);
    cerr << s << endl;

    iss >> r >> c;

    getline(cin, s);
    iss = istringstream(s);

    for range(j, 0, c) {
        char ch;
        iss >> ch;
        key[j] = ch == '1';
    }

    for range(i, 0, r) {
        getline(cin, s);
        iss = istringstream(s);
        for range(j, 0, c) {
            char ch;
            iss >> ch;
            maze[i][j] = ch == '1';
        }
    }

    flip_nut();
   
    bool solved = solve_maze();
    if (solved) {
        cout << "Y" << endl;
    } else {
        flip_nut();
        memset(visited, false, sizeof(visited));
        solved = solve_maze();
        cout << (solved ? "Y" : "N") << endl;
    }

    return 0;
}
