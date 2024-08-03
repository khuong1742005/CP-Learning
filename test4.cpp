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

struct Diamond
{
    double w;
    double c;
};

bool compare(const Diamond &a, const Diamond &b)
{
    return a.w < b.w;
}
void solve()
{
    int n;
    cin >> n;
    vector<Diamond> diamond(n);
    FOR(i, n)
    cin >> diamond[i].w >> diamond[i].c;
    sort(ALL(diamond), compare);
    vector<int> dp(n, 1);
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (diamond[i].c < diamond[j].c)
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    int ans = *max_element(ALL(dp));
    cout << ans << '\n';
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