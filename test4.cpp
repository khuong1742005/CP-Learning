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
    int n, m, k;
    cin >> n >> m >> k;
    string s;
    cin >> s;
    if (m > n)
        yes else
        {
            vector<int> dp(n, 0);
            // base
            for (int i = 0; i < m; i++)
            {
                if (s[i] == 'W')
                {
                    if (s[i + 1] == 'L')
                    {
                        dp[i]++;
                        dp[i + 1] += dp[i];
                    }
                    else if (s[i + 1] == 'W')
                    {
                        dp[i]++;
                        if (s[i - 1] != 'C')
                        {
                            dp[i] += dp[i - 1];
                        }
                    }
                }
            }
            for (auto x : dp)
                cout << x << " ";
            // exponent
        }
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