#include <bits/stdc++.h>
#define MAXL 25
using namespace std;

int n, m, sum;
int s_beg[MAXL], s_end[MAXL], s_temp[MAXL];
int stalls[105], stalls_aux[105];
int c_beg[MAXL], c_end[MAXL], c_temp[MAXL], c_cost[MAXL];


int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);

    cin>>n>>m;


    for(int i = 0; i<n; i++){
        int a, b, temp;
        cin>>a>>b>>temp;
        for(int j = a; j <=b; j++){
            stalls[j]=temp;
            stalls_aux[j] = temp;
        }
    }

    for(int i = 0; i<m; i++){
        cin>>c_beg[i]>>c_end[i]>>c_temp[i]>>c_cost[i];
    }

    int ans = (int)10e9;

    for(int i = 0; i<1<<m; i++){
        int ligados[m] = {0}, money = 0;
        for(int j = 0; j<m; j++){
            if(i&(1<<j))ligados[j] = 1;
            if(ligados[j]){
                money+=c_cost[j];
                for(int k = c_beg[j]; k<=c_end[j]; k++){
                    stalls_aux[k]-=c_temp[j];
                }
            }
        }
        bool isValid = true;
        for(int j = 1; j <= 100; j++){
            if(stalls_aux[j]>0)isValid = false;
            stalls_aux[j] = stalls[j];
        }
        if(isValid)ans=min(ans, money);
    }

    cout<<ans<<endl;
}
