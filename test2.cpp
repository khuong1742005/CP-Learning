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

void remove(string &s, int index)
{
    s.erase(index, 2);
}

void DO1(string &s, int pos1, int &ans, int &n, int y)
{
    while (pos1 < n)
    {
        if (s[pos1] == 'b' && s[pos1 + 1] == 'a')
        {
            remove(s, pos1);
            ans += y;
            pos1 -= 2;
            n -= 2;
        }
        pos1++;
    }
}

void DO2(string &s, int pos2, int &ans, int &n, int x)
{
    while (pos2 < n)
    {
        if (s[pos2] == 'a' && s[pos2 + 1] == 'b')
        {
            remove(s, pos2);
            ans += x;
            pos2 -= 2;
            n -= 2;
        }
        pos2++;
    }
}

void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    int x, y;
    cin >> x;
    cin >> y;
    int ans = 0;
    int pos1 = 0;
    int pos2 = 0;
    if (x > y)
    {
        DO2(s, pos2, ans, n, x);
        DO1(s, pos1, ans, n, y);
    }
    else if (x <= y)
    {
        DO1(s, pos1, ans, n, y);
        DO2(s, pos2, ans, n, x);
    }
    cout << ans;
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