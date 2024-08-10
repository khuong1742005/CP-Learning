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

bool DO(string &s, int k)
{
    int n = s.size();
    REP(i, 1, n / (k + 1))
    {
        string pref = s.substr(0, i);
        string suff = s.substr(n - i);
        string mid = s.substr(i, n - 2 * i);
        if (mid.size() < i * k)
            continue;
        string rever = pref;
        reverse(ALL(rever));
        bool check = true;
        FOR(j, k)
        {
            string seg = mid.substr(j * i, i);
            if (seg != rever)
            {
                check = false;
                break;
            }
        }
        if (check & mid.substr(k * i) == suff)
            return true;
    }
    return false;
}

void solve()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    string s;
    cin >> s;
    if (DO(s, k))
        yes else no
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
