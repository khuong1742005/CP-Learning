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

bool check(int n)
{
    if (n < 2)
        return false;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

void solve()
{
    int n;
    cin >> n;
    int dp[1001] = {0};
    dp[2] = 2;
    dp[3] = 3;
    for (int i = 4; i <= 1000; i++)
    {
        if (i % 2 == 0)
            dp[i] = dp[i / 2] + 2;
        else
        {
            if (check(i))
                dp[i] = i;
            else
            {
                for (int j = i - 1; j > 1; j--)
                {
                    if (i % j == 0)
                    {
                        dp[i] = dp[j] + i / j;
                        break;
                    }
                }
            }
        }
    }
    cout << dp[n] << "\n";
}

signed main()
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
