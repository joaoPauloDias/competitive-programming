#include <bits/stdc++.h>
using namespace std;

struct pt {
    int x, y, id;
};

int orientation(const pt& a, const pt& b, const pt& c) {
    double v = a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y);
    if (v < 0) return -1; // clockwise
    if (v > 0) return +1; // counter-clockwise
    return 0;
}

bool sort_min_pt(const pt& a, const pt& b) {
    return make_pair(a.y, a.x) < make_pair(b.y, b.x);
}

pt min_pt;
bool sort_pts(const pt& a, const pt& b) {
    int o = orientation(min_pt, a, b);
    if (o == 0)
        return (min_pt.x-a.x)*(min_pt.x-a.x) + (min_pt.y-a.y)*(min_pt.y-a.y)
                > (min_pt.x-b.x)*(min_pt.x-b.x) + (min_pt.y-b.y)*(min_pt.y-b.y);
    return o > 0;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int w, h, n;
    cin >> w >> h >> n;

    vector<pt> p;
    for(int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if(((x1 == 0 || x1 == w) && (y1 == 0 || y1 == h)) &&
           ((x2 == 0 || x2 == w) && (y2 == 0 || y2 == h))) {
            pt pt1, pt2;
            pt1.x = x1; pt1.y = y1; pt1.id = i;
            pt2.x = x2; pt2.y = y2; pt2.id = i;
            p.push_back(pt1);
            p.push_back(pt2);
        }
    }

    min_pt = *min_element(p.begin(), p.end(), sort_min_pt);
    remove(p.begin(), p.end(), min_pt);

    sort(p.begin(), p.end(), sort_pts);

    bool visto[n];
    memset(visto, false, sizeof(visto));
    
    stack<int> ids;
    ids.push(min_pt.id);
    visto[min_pt.id] = true;

    bool ok = true;
    for(pt point : p) {
        if(visto[point.id]) {
            if(ids.top() != point.id) {
                ok = false;
                break;
            }
            ids.pop();
        } else {
            ids.push(point.id);
            visto[point.id] = true;
        }
    }

    if(ok) cout << "Y\n";
    else cout << "N\n";

    return 0;

}