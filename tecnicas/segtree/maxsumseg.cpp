#include <bits/stdc++.h>

using namespace std;

struct item{

};

struct segtree{
    int size;
    vector<item> values;

    void init(int n){
        int size = 1;
        while(size<n)size*=2;
        values.resize(2*size);
    }

    void set(int i, int v, int x, int lx, int rx){
        if(rx - lx == 1){
            
        }
    }
    void set(int i, int v){
        set(i, v, 0, 0, size);
    }
};

int main(){

}