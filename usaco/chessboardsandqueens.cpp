#include <bits/stdc++.h>

using namespace std;

char chessboard[10][10];
int res = 0;

bool isOk(int x, int y){
    for(int i = 1; i<=8; i++){
        if(chessboard[i][x] ==  'r' || chessboard[y][i] == 'r')return false;
        if(y-i>= 1 && x-i>=1 && chessboard[y-i][x-i] == 'r') return false;
        if(y-i>= 1 && x+i<=8 && chessboard[y-i][x+i] == 'r')return false;
    }
    return true;
}

void solve(int n){
    if(n>8){res++; return;}
    for(int i = 1; i<= 8; i++){
        if(chessboard[n][i]=='.' && isOk(i, n)){
            chessboard[n][i]='r';
            solve(n+1);
            chessboard[n][i]='.';
        }
    }
}

int main(){
    for(int i = 1; i<=8; i++)
        for(int j = 1; j<=8; j++)
            cin>>chessboard[i][j];

    solve(1);
    cout<<res<<endl;
}
