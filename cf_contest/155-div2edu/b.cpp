#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

int main(){
    int t; cin>>t;
    while(t--){
        ll n; 
        cin>>n;
        ll a[n], b[n];
        ll m_a = INT_MAX, m_b = INT_MAX;
        ll suma = 0, sumb = 0;
        for(int i = 0; i<n; i++){
            cin>>a[i];
            suma+=a[i];
            m_a = min(m_a, a[i]);
        }
        for(int i = 0; i<n; i++){
            cin>>b[i]; 
            sumb+=b[i];
            m_b = min(m_b, b[i]);

        }
        suma += m_b*n;
        sumb += m_a*n;
        cout<<min(suma, sumb)<<endl;
        
    }
}
