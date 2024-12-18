#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> ans;
        int p[n + 1];
        memset(p, 0, sizeof(p));
        int ind = 1;
        for (int i = 0; i < n; i++)
        {
            int aux;
            cin >> aux;
            if (p[aux] == 0)
            {
                ans.push_back(aux);
                p[aux]++;
            }
            else
            {
                while (p[ind] == 1)
                {
                    ind++;
                }
                p[ind] = 1;
                ans.push_back(ind);
            }
        }
        cout << ans[0];
        for (int i = 1; i < n; i++)
        {
            cout << ' ' << ans[i];
        }
        cout << endl;
    }
}