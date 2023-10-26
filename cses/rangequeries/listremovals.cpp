#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct segtree{
    int size;
    vector<int> values;

    void init(int n){
        size = 1;
        while(size<n)size*=2;
        values.assign(2*size, 0LL);
    }
    void set(int i, int v, int x, int lx, int rx){
        if(rx-lx==1){
            values[x] = v;
            return;
        }
        int mid = (lx+rx)/2;
        if(i<mid)set(i, v, 2*x + 1, lx, mid);
        else set(i, v, 2*x + 2, mid, rx);
        values[x] = values[2*x+1]+values[2*x+2];
    }
    void set(int i, int v){
        set(i, v, 0, 0, size);
    }
    // [l, r)
    int calc(int l, int r, int x, int lx, int rx){
        if(l>=rx || lx >=r)return 0LL;
        if(lx>=l && rx<=r)return values[x];
        int mid = (lx+rx)/2;
        int lcalc = calc(l, r, 2*x+1, lx, mid);
        int rcalc = calc(l, r, 2*x+2, mid, rx);
        return lcalc+rcalc;
    }

    int calc(int l, int r){
        return calc(l, r, 0, 0, size);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin>>n;
    segtree st;
    st.init(n);
    int values[n];
    for(int i = 0; i<n; i++){
        cin>>values[i];
        st.set(i, 1);
    }
    for(int i = 0; i<n; i++){
        cin>>q;
        int ini = 0, end = n, m;
        int resp ;
        while(ini<=end){
            m = ini+ (end-ini)/2;
            ll sum = st.calc(0, m);
            if(sum==q){
                resp=m;
                end = m-1;
            }else if(sum>q){
                end = m-1;
            }else{
                ini = m+1;
            }
        }
        if(i>0)cout<<' ';
        cout<<values[resp-1];
        st.set(resp-1, 0);
        // for(int i = 0; i<n; i++){
        //     cout<<st.calc(i, i+1)<<' ';
        // }
        // cout<<endl;
    }
    cout<<endl;
    return 0;
}