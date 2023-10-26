#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct segtree{
    int size;
    vector<ll> values;

    void init(int n){
        size = 1;
        while(size<n)size*=2;
        values.assign(2*size, 0LL);
    }
    // x = current node
    void set(ll i, int v, int x, int lx, int rx){
        //leaf
        if (rx - lx == 1){
            values[x] += v;
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
        values[x] = values[2*x +1] + values[2*x + 2];
    }

    void set(ll i, int v){
        set(i, v, 0, 0, size);
    }

    ll find(int i, int x, int lx, int rx){
        //leaf
        if (rx - lx == 1){
            return values[x];
        }
        int m = (lx+rx)/2;
        //left child
        if(i<m){
            return find(i, 2*x+1, lx, m);
        }else{
        //right child
            return find(i, 2*x+2, m, rx);
        }
    }

    ll find(int i){
        find(i, 0, 0, size);
    }

    ll calc(int l, int r, int x, int lx, int rx){
        //case 1: disjoint
        if (lx >= r || l >=rx) return 0;
        //case 2: totally included
        if(lx>=l && rx<=r)return values[x];


        //case 3: parcially included
        int m = (lx+rx)/2;
        ll sl = calc(l, r, 2*x +1, lx, m);
        ll sr = calc(l,r,2*x +2, m, rx);
        return sl+sr;
    }

    ll calc(int l, int r){
        return calc(l, r, 0, 0, size);
    }
};


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin>>n>>q;
    ll a[n];
    segtree st;
    st.init(n+1);

    cin>>a[0];
    for(int i = 1; i<n; i++){
        cin>>a[i];
    }
    
    while(q--){
        int op; cin>>op;
        if(op==1){
            int l, r, u;
            cin>>l>>r>>u;
            l--;
            st.set(l, u);
            st.set(r, -u);
        }else{
            int k; cin>>k;
            cout<<a[k-1]+st.calc(0, k)<<endl;
        }
    }
    
    return 0;
}