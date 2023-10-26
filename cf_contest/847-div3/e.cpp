#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int xxor, sum, aand;
        cin>>xxor;
        sum = 2*xxor;
        aand = xxor/2;
        int a = 0, b = 0;
        for(int i = 31; i>=0; i--)
        {
            if(aand&(1<<i))
            {
                a = a | (1<<i);
                b = b | (1<<i);
            }
        }
        for(int i = 31; i>=0; i--)
        {
            if(xxor&(1<<i))
            {
                a = a | (1<<i);
            }
        }
        if(a+b==sum)cout<<a<<' '<<b<<endl;
        else cout<<-1<<endl;
    }
}
