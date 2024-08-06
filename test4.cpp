#include <bits/stdc++.h>
#define ll long long
#define db double
#define fl float
#define FOR(i, n) for (int i = 0; i < (n); i++)
#define REP(i, a, b) for (int i = (a); i <= (b); i++)
#define vi vector<int>
#define vsz n
#define ssz s.size()
#define SZ(x) (x).size()
#define ALL(x) (x).begin(), (x).end()
#define pb(x) (x).push_back
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#pragma GCC optimize("03")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2")
#define int long long
using namespace std;

void solve()
{
    string s, x;
    cin >> s >> x;
    int posx = 0;
    int poss = 0;
    while (posx < x.size() && poss < s.size())
    {
        if (s[poss] == x[posx])
        {
            poss++;
            posx++;
        }
        else
        {
            if (s[poss] != '?')
                poss++;
            else
            {
                s[poss] = x[posx];
                poss++;
                posx++;
            }
        }
    }
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '?')
            s[i] = 'a';
    }
    int pos1 = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == x[pos1])
        {
            pos1++;
            if (pos1 == x.size())
            {
                yes
                        cout
                    << s << endl;
                return;
            }
        }
    }
    no
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    // int t = 1;
    while (t--)
    {
        solve();
    }

    return 0;
}