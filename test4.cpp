#include <bits/stdc++.h>
#define ll long long
#define db double
#define fl float
#define FOR(i, n) for (int i = 0; i < (n); i++)
#define REP(i, a, b) for (int i = (a); i <= (b); i++)
#define vi vector<int>
#define vsz v.size()
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
    int n;
    cin >> n;
    string s = to_string(n);
    sort(s.begin(), s.end());
    vector<string> p;
    for (int i = 0; i <= 30; i++)
    {
        int x = pow(2, i);
        p.push_back(to_string(x));
    }
    for (int i = 0; i <= 30; i++)
    {
        sort(p[i].begin(), p[i].end());
    }
    for (int i = 0; i <= 30; i++)
    {
        if (p[i] == s)
            yes
    }
    no
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int t; cin >> t;
    int t = 1;
    while (t--)
    {
        solve();
    }

    return 0;
}