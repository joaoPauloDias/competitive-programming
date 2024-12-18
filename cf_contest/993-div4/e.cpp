#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll k, l1, r1, l2, r2;
        cin >> k >> l1 >> r1 >> l2 >> r2;
        ll kn = 1;

        ll ans = 0;
        for (int i = 0; i < 32; i++)
        {
            if (kn > r2)
                break;
            ll lower_bound = -1;
            ll left = l1, right = r1, x;
            while (left <= right)
            {
                x = left + (right - left) / 2;
                ll y = kn * x;
                // cout << "left " << left << "\nright " << right << endl;
                // cout << "x = " << x << "\ny = " << y << endl;
                if (y >= l2 && y <= r2)
                {
                    right = x - 1;
                    lower_bound = x;
                }
                else if (y > r2)
                    right = x - 1;
                else
                    left = x + 1;
            }

            ll upper_bound = -1;
            left = l1, right = r1;

            while (left <= right)
            {
                x = left + (right - left) / 2;
                ll y = kn * x;
                if (y >= l2 && y <= r2)
                {
                    left = x + 1;
                    upper_bound = x;
                }
                else if (y > r2)
                    right = x - 1;
                else
                    left = x + 1;
            }
            if (lower_bound != -1 && upper_bound != -1)
                ans += upper_bound - lower_bound + 1;
            kn = kn * k;
        }
        cout << ans << endl;
    }
}