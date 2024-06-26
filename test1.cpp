#include <bits/stdc++.h>
#define ll long long
#define db double
#define fl float
#define FOR(i, n) for (int i = 0; i < (n); i++)
#define REP(i, a, b) for (int i = (a); i <= (b); i++)
#define vi vector<int>
#define SZ(x) (x).size()
#define ALL(x) (x).begin(), (x).end()
#define pb(x) (x).push_back
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#pragma GCC optimize("03")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2")

using namespace std;

int DO(int a, int b, int ans)
{
    if (a % 3 != 0)
    {
        int tmp = a % 3;
        a += 3 - tmp;
        b -= 3 - tmp;
    }
    ans += a / 3;
    if (b > 0)
    {
        ans += b / 3;
        b -= (b / 3) * 3;
        if (b == 0)
            return ans;
        if (b < 3)
            return ans + 1;
        if (b != 0)
            return ans + 1;
        return ans;
    }
    else if (b == 0)
        return ans;
    else
        return -1;
}

void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    int ans = 0;
    ans += a;
    if (DO(b, c, ans) == -1)
    {
        cout << -1 << endl;
        return;
    }
    else
    {
        cout << DO(b, c, ans) << endl;
    }
}
int main()
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