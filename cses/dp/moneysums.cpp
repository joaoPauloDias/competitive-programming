#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin>>n;
    int w[n];
    int W = 0;
    for(int i = 0; i<n; i++){cin>>w[i];W+=w[i];}
    bool possible[W+1];
    memset(possible, false, sizeof(possible));
    possible[0] = true;
    for(int i = 0; i<n; i++){
        for(int j = W; j>=0; j--){
            if(j+w[i]<=W)possible[j+w[i]]|=possible[j];
        }
    }
    vector<int> ans;
    for(int i = 1; i<= W; i++){
        if(possible[i]){
            ans.push_back(i);
        }
    }

    cout<<ans.size()<<endl;
    cout<<ans[0];
    for(int i = 1; i<ans.size(); i++){
        cout<<" "<<ans[i];
    }
    cout<<endl;
    return 0;
}