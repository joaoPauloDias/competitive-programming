#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct segtree{
    int size;
    vector<int> values;

    void init(int n){
        size = 1;
        while(size<n)size*=2;
        values.assign(2*size, 0);
    }
    // x = current node
    void set(int i, int v, int x, int lx, int rx){
        //leaf
        if (rx - lx == 1){
            values[x] = v;
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

    void set(int i, int v){
        set(i, v, 0, 0, size);
    }

    int calc(int l, int r, int x, int lx, int rx){
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

    int calc(int l, int r){
        return calc(l, r, 0, 0, size);
    }

};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;

        segtree st;
        st.init(n);

        ll ans = 0LL;
        int values[n];
        int querys[n];

        for(int i = 0; i<n; i++){
            cin>>querys[i];
            values[i] = querys[i];           
        }

        sort(values, values+n);
        map<int, int> comp;
        comp.clear();
        for(int i = 0; i< n; i++){
            if(comp[values[i]]==0){
                comp[values[i]] = i;
            }
        }

        for(int i = 0; i<n; i++){
            ans+=st.calc(comp[querys[i]]+1, n+1);
            st.set(comp[querys[i]], 1);
        }
        cout<<ans<<endl;
    }
        

        

   
        
}