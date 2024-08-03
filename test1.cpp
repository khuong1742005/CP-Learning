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
    string a, b, c;
    int pos = 0;
    bool checkMinus1 = false, checkMinus2 = false, checkMinus3 = false;
    bool checkZero1 = false, checkZero2 = false, checkZero3 = false;
    char ope1, ope2;
    if (s[0] == '-')
    {
        checkMinus1 = true;
        pos++;
    }
    if (s[pos] == '?')
        checkZero1 = true;
    while (s[pos] != '+' && s[pos] != '-' && s[pos] != '*')
    {
        a += s[pos];
        pos++;
    }
    ope1 = s[pos];
    pos++;
    if (s[pos] == '-')
    {
        checkMinus2 = true;
        pos++;
    }
    if (s[pos] == '?')
        checkZero2 = true;
    while (s[pos] != '=')
    {
        b += s[pos];
        pos++;
    }
    ope2 = s[pos];
    pos++;
    if (s[pos] == '-')
    {
        checkMinus3 = true;
        pos++;
    }
    if (s[pos] == '?')
        checkZero3 = true;
    while (pos < s.size())
    {
        c += s[pos];
        pos++;
    }
    int start = 0;
    if (checkZero1 == true || checkZero2 == true || checkZero3 == true)
        start = 1;
    for (int i = start; i <= 9; i++)
    {
        string tmpa = a, tmpb = b, tmpc = c;
        for (int j = 0; j < a.size(); j++)
        {
            if (a[j] == '?')
                tmpa[j] = i + '0';
        }
        for (int j = 0; j < b.size(); j++)
        {
            if (b[j] == '?')
                tmpb[j] = i + '0';
        }
        for (int j = 0; j < c.size(); j++)
        {
            if (c[j] == '?')
                tmpc[j] = i + '0';
        }
        int n = 0, m = 0, p = 0;
        int asz = a.size(), bsz = b.size(), csz = c.size();
        for (int j = 0; j < asz; j++)
        {
            n = n * 10 + (tmpa[j] - '0');
        }
        for (int j = 0; j < bsz; j++)
        {
            m = m * 10 + (tmpb[j] - '0');
        }
        for (int j = 0; j < csz; j++)
        {
            p = p * 10 + (tmpc[j] - '0');
        }
        if (checkMinus1 == true)
            n = -n;
        if (checkMinus2 == true)
            m = -m;
        if (checkMinus3 == true)
            p = -p;
        if (ope1 == '-')
        {
            if (n - m == p)
            {
                cout << i << endl;
                return;
            }
            else
                continue;
        }
        else if (ope1 == '+')
        {
            // cout << n << " " << m << " " << p << endl;
            if (n + m == p)
            {
                cout << i << endl;
                return;
            }
            else
                continue;
        }
        else if (ope1 == '*')
        {
            if (n * m == p)
            {
                cout << i << endl;
                return;
            }
            else
                continue;
        }
    }
    cout << -1 << endl;
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
