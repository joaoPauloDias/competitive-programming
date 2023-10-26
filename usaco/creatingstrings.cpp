#include <bits/stdc++.h>
using namespace std;

int ans = 0, len;
vector<string>aux;
int options[26];
void permutations(int n, string atual)
{
    if(n==len)
    {
        aux.push_back(atual);
        return;
    }
    for(int i = 0; i < 26; i++)
    {
        if(options[i]>0)
        {
            options[i]--;
            permutations(n+1, atual+char('a'+i));
            options[i]++;
        }
    }
}

int main()
{
    string in;
    cin>>in;
    len = in.length();
    for(int i = 0; i<len; i++)
        options[in[i]-'a']++;
    permutations(0, "");
    cout<<aux.size()<<endl;
    for (auto i : aux)
        cout << i << endl;
}
