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
    vector<int> rowSum(5);
    vector<int> colSum(5);
    for (int i = 0; i < rowSum.size(); i++)
        cin >> rowSum[i];
    for (int i = 0; i < colSum.size(); i++)
        cin >> colSum[i];
    int n = rowSum.size();
    int m = colSum.size();
    vector<vector<int>> v(n, vector<int>(m, 0));
    int posR = 0, posC = 0;
    int posJ = 0;
    for (int i = 0; i < m; i++)
    {
        if (colSum[posC] < rowSum[posR])
        {
            v[0][posJ] = colSum[posC];
            rowSum[posR] -= colSum[posC];
            posJ++;
            posC++;
        }
        else
        {
            v[0][posJ] = rowSum[posR];
            posR++;
            break;
        }
    }

    for (int i = 1; i < n; i++)
    {
        v[i][posJ] = colSum[posC] - v[i - 1][posJ];
        v[i][posJ + 1] = rowSum[posR] - v[i][posJ];
        posC++;
        posR++;
        posJ++;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
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