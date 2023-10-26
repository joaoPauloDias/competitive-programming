#include <bits/stdc++.h>
//unfinished
using namespace std;

int memo[150][150];
vector<int> a[200005];
vector<int> resp;
int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n, first, first_count = 1, actual_first, index = 0;
        cin>>n;

        cin>>first;
        memo[0][0] = first;
        actual_first = first;
        for(int j = 1; j<n-1; j++)
        {
            cin>>memo[0][j];
        }

        for(int i = 1; i<n; i++)
        {
            cin>>memo[i][0];
            if(memo[i][0]==first)
            {
                first = memo[i][0];
                first_count++;
            }
            else if(first_count>1)
            {
                first = memo[i][0];
                first_count = 1;
                actual_first = memo[i][0];
                index=i;
            }
            for(int j = 1; j<n-1; j++)
                cin>>memo[i][j];
        }

            cout<<index>=n?memo[index-1][0];
            for(int i = 0; i < n-1; i++)
                cout<<' '<<memo[index][i];
            cout<<endl;


    }
}

