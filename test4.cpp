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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> nums1(n, vector<int>(2));
    vector<vector<int>> nums2(m, vector<int>(2));
    FOR(i, n)
    {
        FOR(j, 2)
        cin >> nums1[i][j];
    }
    FOR(i, m)
    {
        FOR(j, 2)
        cin >> nums2[i][j];
    }
    vector<vector<int>> v(n + m, vector<int>(2, 0));
    for (int i = 0; i < n; i++)
    {
        int pos = nums1[i][0];
        v[pos][0] = pos;
        v[pos][1] = nums1[i][1];
    }
    for (int i = 0; i < m; i++)
    {
        int pos = nums2[i][0];
        if (v[pos][1] > 0)
        {
            cout << "check " << pos << endl;
            v[pos][1] += nums2[i][1];
        }
        else
        {
            v[pos][0] = pos;
            v[pos][1] = nums2[i][1];
        }
    }

    FOR(i, v.size())
    {
        FOR(j, 2)
        {
            cout << v[i][j] << " ";
        }
        cout << '\n';
    }
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