#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct segtree{
    int size;
    vector<ll> sums;
    vector<int> count;

    void init(int n){
        size = 1;
        while(size<n)size*=2;
        sums.assign(2*size, 1e9);
        count.assign(2*size, 0);
    }
    // x = current node
    void set(int i, int v, int x, int lx, int rx){
        //leaf
        if (rx - lx == 1){
            sums[x] = v;
            count[x] = 1;
            return;
        }
        int m = (lx+rx)/2;
        //left child
        if(i<m){
            set(i, v, 2*x+1, lx, m);
        }else{
        //right child
            set(i,v, 2*x+2, m, rx);
        }
        // update sum of actual node after recursion
        if(sums[2*x +1]<sums[2*x + 2]){
            sums[x] = sums[2*x +1];
            count[x] = count[2*x +1];
        }else if(sums[2*x +1]>sums[2*x + 2]){
            sums[x] = sums[2*x +2];
            count[x] = count[2*x +2];
        }else{
            sums[x] = sums[2*x +2];
            count[x] = count[2*x +1]+count[2*x +2];
        }
    }

    void set(int i, int v){
        set(i, v, 0, 0, size);
    }

    pair<int, ll> min_s(int l, int r, int x, int lx, int rx){
        //case 1: disjoint
        if (lx >= r || l >=rx) return {0, 1e9};
        //case 2: totally included
        if(lx>=l && rx<=r)return {count[x], sums[x]};
        //case 3: parcially included
        int m = (lx+rx)/2;
        pair<int, ll> sl = min_s(l, r, 2*x +1, lx, m);
        pair<int, ll> sr = min_s(l,r,2*x +2, m, rx);

        if(sl.second<sr.second)return sl;
        if(sr.second<sl.second)return sr;
        return {sl.first+sr.first, sl.second};
    }

    pair<int, ll> min_s(int l, int r){
        return min_s(l, r, 0, 0, size);

    }

};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m; cin>>n>>m;

    segtree st;
    st.init(n);
    for(int i = 0; i<n; i++){
        int v; cin>>v;
        st.set(i, v);
    }

    while(m--){
        int op; cin>>op;
        if(op==1){
            int i, v; cin>>i>>v;
            st.set(i, v);
        }else{
            int l, r;
            cin>>l>>r;
            pair<int, ll> ans = st.min_s(l,r);
            cout<<ans.second<<' '<<ans.first<<endl;

        }

    }
}