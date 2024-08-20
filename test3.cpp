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

#define ll long long
using namespace std;

void EqualRow(string s1, string s2)
{
    if (s1[0] > s2[0])
    {
        int tmp = (s1[0] - 'A') - (s2[0] - 'A');
        cout << tmp << endl;
        while (tmp--)
            cout << 'L' << '\n';
    }
    else
    {
        int tmp = (s2[0] - 'A') - (s1[0] - 'A');
        cout << tmp << endl;
        while (tmp--)
            cout << 'R' << '\n';
    }
}
void EqualCol(string s1, string s2)
{
    if (s1[1] > s2[1])
    {
        int tmp = (s1[1] - '0') - (s2[1] - '0');
        cout << tmp << endl;
        while (tmp--)
            cout << 'D' << '\n';
    }
    else
    {
        int tmp = (s2[1] - '0') - (s1[1] - '0');
        cout << tmp << endl;
        while (tmp--)
            cout << 'U' << '\n';
    }
}

void solve()
{
    string s1, s2;
    cin >> s1 >> s2;
    if (s1 == s2)
        cout << 0;
    else if (s1[0] == s2[0])
    {
        EqualCol(s1, s2);
    }
    else if (s1[1] == s2[1])
    {
        EqualRow(s1, s2);
    }
    else
    {
        int c1 = s1[0] - 'a', c2 = s2[0] - 'a';
        int r1 = s1[1] - '0', r2 = s2[1] - '0';
        // row > col >
        if (s1[0] > s2[0] && s1[1] > s2[1])
        {
            if (c1 - c2 < r1 - r2)
            {
                cout << r1 - r2 << '\n';
                while (c1 != c2)
                {
                    cout << "LD" << '\n';
                    c1--;
                    r1--;
                }
                while (r1 != r2)
                    cout << 'D' << '\n',
                        r1--;
            }
            else
            {
                cout << c1 - c2 << '\n';
                while (r1 != r2)
                {
                    cout << "LD" << '\n';
                    r1--;
                    c1--;
                }
                while (c1 != c2)
                    cout << 'L' << '\n',
                        c1--;
            }
        }
        // row > col <
        else if (s1[0] < s2[0] && s1[1] > s2[1])
        {
            if (c2 - c1 < r1 - r2)
            {
                cout << r1 - r2 << '\n';
                while (c1 != c2)
                {
                    cout << "RD" << '\n';
                    c1++;
                    r1--;
                }
                while (r1 != r2)
                    cout << 'D' << '\n',
                        r1--;
            }
            else
            {
                cout << c2 - c1 << '\n';
                while (r1 != r2)
                {
                    cout << "RD" << '\n';
                    r1--;
                    c1++;
                }
                while (c1 != c2)
                    cout << 'R' << '\n',
                        c1++;
            }
        }
        // row < col <
        else if (s1[0] < s2[0] && s1[1] < s2[1])
        {
            if (c2 - c1 < r2 - r1)
            {
                cout << r2 - r1 << '\n';
                while (c1 != c2)
                {
                    cout << "RU" << '\n';
                    c1++;
                    r1++;
                }
                while (r1 != r2)
                    cout << 'U' << '\n',
                        r1++;
            }
            else
            {
                cout << c2 - c1 << '\n';
                while (r1 != r2)
                {
                    cout << "RU" << '\n';
                    r1++;
                    c1++;
                }
                while (c1 != c2)
                    cout << 'R' << '\n',
                        c1++;
            }
        }
        // row < col >
        else if (s1[0] > s2[0] && s1[1] < s2[1])
        {
            if (c1 - c2 < r2 - r1)
            {
                cout << r2 - r1 << '\n';
                while (c1 != c2)
                {
                    cout << "LU" << '\n';
                    c1--;
                    r1++;
                }
                while (r1 != r2)
                    cout << 'U' << '\n',
                        r1++;
            }
            else
            {
                cout << c1 - c2 << '\n';
                while (r1 != r2)
                {
                    cout << "LU" << '\n';
                    r1++;
                    c1--;
                }
                while (c1 != c2)
                    cout << 'L' << '\n',
                        c1--;
            }
        }
    }
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
