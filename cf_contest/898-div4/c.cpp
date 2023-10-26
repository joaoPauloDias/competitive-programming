#include <bits/stdc++.h>

using namespace std;

typedef long long int  ll;
const int INF = 1e6 +5;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t;
    while(t--){
        char m[15][15];
        for(int i = 1; i<=10; i++){
            for(int j = 1; j<=10; j++){
                cin>>m[i][j];
            }
        }
        int score = 0;
        for(int i = 1; i<=10; i++){
            for(int j = 1; j<=10; j++){
                if(m[i][j]=='X'){
                    if(i==1 || i==10 || j==10 || j==1)score+=1;
                    else if(i==2 || i==9 || j==9 || j==2)score+=2;
                    else if(i==3 || i==8 || j==8 || j==3)score+=3;
                    else if(i==4 || i==7 || j==7 || j==4)score+=4;
                    else if(i==5 || i==6 || j==6 || j==5)score+=5;
                }
            }
        }

        cout<<score<<endl;
    }

    

    return 0;
}