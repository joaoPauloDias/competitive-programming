#include <bits/stdc++.h>
#define MAXL 10005
using namespace std;

int sum(int a, int b){
    int r_and, r_or, r_xor, r_sum;

    cout<<"and "<<a<<' '<<b<<endl;
    cin>>r_and;
    cout<<"or "<<a<<' '<<b<<endl;
    cin>>r_or;

    r_xor = ~(r_and)&r_or;
    r_sum = 2*r_and + r_xor;
    return r_sum;
}

int main(){
    //fflush(stdout)
    int n, k, sum_ant;
    cin>>n>>k;
    vector<int> v;

    int s1 = sum(1,2), s2 = sum(2,3), s3 = sum(1,3);
    v.push_back((s1+s3-s2)/2);
    v.push_back(s1 - v[0]);
    v.push_back(s2 - v[1]);
    for(int i = 4; i<=n; i++){
        int aux = sum(i-1, i);
        v.push_back(aux - v[i-2]);
    }
    sort(v.begin(), v.end());
    cout<<"finish "<<v[k-1]<<endl;

}
