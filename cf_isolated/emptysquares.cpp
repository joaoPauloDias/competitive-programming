#include <bits/stdc++.h>

using namespace std;

int n, k, e;

#define range(x, l, u) (long long x = (l); x < (u); x++)
#define let auto
#define debug_var(x) #x " = " << (x)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k >> e;

    int left = e;
    int right = n - k - e;

    long long res = n;

    for range(t, 0, n+1) {
        for range(tt, 0, t+1) {
            let t1 = t-tt;
            let t2 = t-t1;

            for range(i, 0, left+1) {
                let p1 = i;
                let p2 = left-i-t1;

                if (p2 < 0) continue;
                if ((p1 != 0 && p1 == p2) || p1 == k || p2 == k) continue;

                for range(j, 0, right+1) {
                    let q1 = j;
                    let q2 = right-j-t2;

                    if (q2 < 0) continue;
                    if ((q1 != 0 && q1 == q2) || q1 == k || q2 == k) continue;
                    if (((p1 != 0) && (p1 == q1 || p1 == q2)) || ((p2 != 0) && (p2 == q1 || p2 == q2))) continue;

                    cout << (t1+t2) << endl;
                    return 0;
                }
            }
        }
    }

    cout << "0" << endl;
    return 0;
}