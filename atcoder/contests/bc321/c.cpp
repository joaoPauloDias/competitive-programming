#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> s;
void generate(string aux, int len){
    if(len>10)return;
    s.push_back(stoll(aux));
    for(int i = 0; i<aux[len-1]-'0'; i++){
        char l = '0'+i;
        
        generate(aux+l, len+1);
    }
}
int main(){
    generate("1", 1);
    generate("2", 1);
    generate("3", 1);
    generate("4", 1);
    generate("5", 1);
    generate("6", 1);
    generate("7", 1);
    generate("8", 1);
    generate("9", 1);
    sort(s.begin(), s.end());
    ll k; cin>>k;
    cout<<s[k-1]<<endl;
    
}