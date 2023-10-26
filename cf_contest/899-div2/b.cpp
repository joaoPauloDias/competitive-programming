#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //qual o maior conjunto que eu posso fazer não botando o número n
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int freq[n][51];
        int tfreq[51];
        memset(freq, 0, sizeof(freq));
        memset(tfreq, 0, sizeof(tfreq));
        for(int i = 0; i<n; i++){
            int k; cin>>k;
            for(int j = 0; j<k; j++){
                int element; cin>>element;
                freq[i][element]++;
                tfreq[element]++;
            }
        }
        int r = 0;
        for(int i = 1; i<=50; i++){
            if(tfreq[i]==0)continue;
            int auxfreq[51];
            memset(auxfreq, 0, sizeof(auxfreq));
            for(int j = 0; j<n; j++){
                if(freq[j][i]==0){
                    for(int k = 1; k<=50; k++){
                        auxfreq[k]+=freq[j][k];
                    }
                }
            }
            int aux = 0;
            for(int j = 1; j<=50; j++){
                if(auxfreq[j]>0)aux++;
            }
            r = max(r, aux);
        }
        cout<<r<<endl;
    }
    return 0;
}