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
    int n, s, m;
    cin >> n >> s >> m;
    vector<pair<int, int>> v;
    FOR(i, n)
    {
        int l, r;
        cin >> l;
        cin >> r;
        v.push_back({l, r});
    }
    if (v[0].first >= s)
    {
        yes return;
    }
    if (m - v[n - 1].second >= s)
    {
        yes return;
    }
    for (int i = 1; i < n; i++)
    {
        if (v[i].first - v[i - 1].second >= s)
        {
            yes return;
        }
    }
    no
    // for (auto x : v)
    //     cout << x.first << " " << x.second << endl;
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
