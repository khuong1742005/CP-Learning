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
const int N = 1e9 + 7;
void solve()
{
    int k;
    cin >> k;
    string s;
    cin >> s;
    int n = s.size();
    int pos = 0;
    int cnt = 0;
    while (k--)
    {
        if (pos < n - 1)
        {
            char Max = s[pos];
            int posj = pos;
            for (int j = pos + 1; j < n; j++)
            {
                if (s[j] > Max)
                {
                    Max = s[j];
                    posj = j;
                }
            }
            swap(s[pos], s[posj]);
            pos++;
            cnt++;
        }
    }
    if (cnt < k)
    {
        int tmp = k - cnt;
        if (tmp % 2 == 0)
            cout << s;
        else
        {
            swap(s[n - 1], s[n - 2]);
            cout << s;
        }
    }
    else
        cout << s;
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
