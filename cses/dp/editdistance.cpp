#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string s1, s2;
vector<vector<int>> dp(5005, vector<int>(5005, 0));
int edit(int a, int b){
    for(int i = 0; i<=a; i++){
        for(int j = 0; j<=b; j++){
            if(i==0){ dp[i][j] = j; continue; }
            if(j==0){ dp[i][j] = i; continue; }
            if(s1[i-1]==s2[j-1]){dp[i][j] = dp[i-1][j-1]; continue;}
            
            dp[i][j] = 1+ min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]});
            
        }
    }
    return dp[a][b];
    // if(a<0)return b+1;
    // if(b<0)return a+1;
    // if(dp[a][b]!=-1)return dp[a][b];
    
    // return dp[a][b] = min({1 + edit(a-1, b), 1 + edit(a, b-1), edit(a-1, b-1) + int(!(s1[a]==s2[b])), 1 + edit(a, b-1)});

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>s1>>s2;

    cout<<edit(s1.size(), s2.size())<<endl;
    
   

    return 0;
}