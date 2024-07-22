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

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<string> names(n);
    vector<int> heights(n);
    FOR(i, n)
    cin >> names[i];
    FOR(i, n)
    cin >> heights[i];
    vector<pair<int, string>> v;
    for (int i = 0; i < n; i++)
    {
        v.push_back({heights[i], names[i]});
    }
    sort(v.begin(), v.end());
    FOR(i, n)
    cout << v[i].first << " " << v[i].second << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int t;
    // cin >> t;
    int t = 1;
    while (t--)
    {
        solve();
    }

    return 0;
}