#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxl = 5050;
const int inf = 1e9;
pair < int, pair < int, int >> task[maxl]; // d, t e id
vector < int > ord, prefix, times;

bool comp_task(int a, int b) {
    return task[a] < task[b];
}

int n, current;

bool test() {
    int t_a = 0;
    times.clear();
    for (int i = 0; i < n; i++) {
        int aux = ord[i];
        t_a += task[aux].second.first;

        if (i > current) {
            times.push_back(task[aux].first - t_a);
        } else {
            times.push_back(inf);
        }

        if (t_a > task[aux].first)
            return false;
    }
    prefix.resize(n);
    prefix[0] = times[0];
    for (int i = 1; i < n; i++)
        prefix[i] = min(prefix[i - 1], times[i]);

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    current = -1;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> task[i].second.first >> task[i].first;
        task[i].second.second = i;
        ord.push_back(i);
    }

    sort(ord.begin(), ord.end(), comp_task);

    bool consegue = test();
    if (!consegue) {
        cout << "*\n";
        return 0;
    }

    for (int i = 0; i < n; i++) {
        vector < int > pos(n);
        for (int j = 0; j < n; j++)
            pos[ord[j]] = j;
        int best_i = inf;
        for (int j = 0; j < n; j++) {
            if (pos[j] < i) continue;
            if (pos[j] == i) {
                best_i = j;
                break;
            }
            if (prefix[pos[j] - 1] >= task[j].second.first) {
                best_i = j;
                break;
            }
        }
        current++;
        for (int j = pos[best_i] - 1; j >= i; j--)
            ord[j + 1] = ord[j];
        ord[i] = best_i;
        test();

    }
    for (auto i: ord)
        cout << i + 1 << ' ';
    cout << endl;

    return 0;
}