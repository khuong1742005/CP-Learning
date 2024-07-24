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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    FOR(i, n)
    {
        FOR(j, m)
        cin >> grid[i][j];
    }
    vector<int> vR, vC;
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
                cnt++;
        }
        if (cnt >= 2)
            vR.push_back(i);
    }
    for (int i = 0; i < m; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (grid[j][i] == 1)
                cnt++;
        }
        if (cnt >= 2)
            vC.push_back(i);
    }

    map<string, bool> mp;
    for (int i = 0; i < vR.size(); i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[vR[i]][j] == 1)
            {
                string s = to_string(vR[i]) + to_string(j);
                mp.insert(make_pair(s, true));
            }
        }
    }
    for (int i = 0; i < vC.size(); i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[j][vC[i]] == 1)
            {
                string s = to_string(j) + to_string(vC[i]);
                if (mp.find(s) == mp.end())
                    mp.insert(make_pair(s, true));
                else
                    continue;
            }
        }
    }
    cout << mp.size();
    // for (auto x : vC)
    //     cout << x << " ";
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