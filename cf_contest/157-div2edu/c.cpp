#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin>>n;
    string s[n];

    int freq[50][10];
    memset(freq, 0, sizeof(freq));

    int soma_esq[n];
    int soma_dir[n];
    int soma_esq2[n];
    int soma_dir2[n];

    int somas[n];
    int len[n];

    ll ans = 0;
    for(int i = 0; i<n; i++){
        cin>>s[i];
        int aux = s[i].length();
        len[i] = aux;
        int soma = 0;
        for(int j = 0; j<aux; j++){
            soma+=s[i][j]-'0';
        }

        freq[soma][aux]++;
        somas[i] = soma;
        soma_dir[i] = soma-2*(s[i][aux-1]-'0');
        soma_esq[i] = soma-2*(s[i][0]-'0');
        if(aux==5){
            soma_dir2[i] = soma_dir[i] - 2*(s[i][aux-2]-'0');
            soma_esq2[i] = soma_esq[i] - 2*(s[i][1]-'0');
        }
        
    }
    
    for(int i = 0; i < n; i++){
        //cout<<s[i]<<' '<<somas[i]<<' '<<soma_dir[i]<<' '<<soma_esq[i]<<endl;
        if(len[i]==5){
            //cout<<soma_dir2[i]<<' '<<soma_esq2[i]<<endl;
        }
        ans+=freq[somas[i]][len[i]]-1;
       if(len[i]==3){
            if(soma_esq[i]>=0) ans+= freq[soma_esq[i]][1];
            if(soma_dir[i]>=0) ans+= freq[soma_dir[i]][1];
        }
        if(len[i]==4){
            if(soma_esq[i]>=0) ans+= freq[soma_esq[i]][2];
            if(soma_dir[i]>=0) ans+= freq[soma_dir[i]][2];
        }
        if(len[i]==5){
            if(soma_esq[i]>=0) ans+=  + freq[soma_esq[i]][3];
            if(soma_dir[i]>=0) ans+=+ freq[soma_dir[i]][3];
            if(soma_esq2[i]>=0) ans+= freq[soma_esq2[i]][1];
            if(soma_dir2[i]>=0) ans+= freq[soma_dir2[i]][1];
        }
    }
    cout<<ans+n<<endl;
        
    return 0;
}