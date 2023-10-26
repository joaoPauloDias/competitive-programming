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
    void set(int i, ll v, int x, int lx, int rx){
        if(rx-lx==1){
            values[x] = v;
            return;
        }
        int mid = (lx+rx)/2;
        if(i<mid)set(i, v, 2*x + 1, lx, mid);
        else set(i, v, 2*x + 2, mid, rx);
        values[x] = values[2*x+1]+values[2*x+2];
    }
    void set(int i, ll v){
        set(i, v, 0, 0, size);
    }
    // [l, r)
    ll calc(int l, int r, int x, int lx, int rx){
        if(l>=rx || lx >=r)return 0LL;
        if(lx>=l && rx<=r)return values[x];
        int mid = (lx+rx)/2;
        ll lcalc = calc(l, r, 2*x+1, lx, mid);
        ll rcalc = calc(l, r, 2*x+2, mid, rx);
        return lcalc+rcalc;
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
    segtree st;
    st.init(n);
    for(int i = 0; i<n; i++){
        ll aux; cin>>aux;
        st.set(i, aux);
    }
    for(int i = 0; i<q; i++){
        int l, r; cin>>l>>r;
        cout<<st.calc(l-1, r)<<endl;
    }
    return 0;
}