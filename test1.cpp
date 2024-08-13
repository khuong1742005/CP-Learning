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
    string s;
    cin >> s;
    int n = s.length();
    int pos1 = 0;
    int pos2 = 0;
    string ans = "";
    stack<char> t;
    while (true)
    {
        char c = 'z';
        for (int i = pos1; i < n; i++)
        {
            if (s[i] < c)
            {
                c = s[i];
                pos2 = i;
            }
        }
        for (int i = pos1; i < pos2; i++)
        {
            t.push(s[i]);
        }
        ans += c;
        pos1 = pos2 + 1;
        if (pos2 == n - 1)
            break;
    }
    // while (!t.empty())
    // {
    //     ans += t.top();
    //     t.pop();
    // }
    cout << ans << "\n";
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
