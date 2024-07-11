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

void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    int start = 0;
    int end = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
            start = i;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == ')')
        {
            if (s[i - 1] != '(' && s[i - 2] != '(')
                end = i;
        }
    }
    vector<char> tmp;
    for (int i = start; i <= end; i++)
    {
        if (s[i] != '(' && s[i] != ')')
            tmp.push_back(s[i]);
    }
    reverse(tmp.begin(), tmp.end());
    int pos = 0;
    for (int i = start; i <= end; i++)
    {
        if (s[i] != '(' && s[i] != ')')
        {
            s[i] = tmp[pos];
            pos++;
        }
    }
    start--;
    end++;
    while (start >= 0 and end <= n - 1)
    {
        if (s[start] == '(')
        {
            while (end <= n - 1)
            {
                if (s[end] == ')')
                {
                    vector<char> tmp;
                    for (int i = start; i <= end; i++)
                    {
                        if (s[i] != '(' && s[i] != ')')
                            tmp.push_back(s[i]);
                    }
                    reverse(tmp.begin(), tmp.end());
                    int pos = 0;
                    for (int i = start; i <= end; i++)
                    {
                        if (s[i] != '(' && s[i] != ')')
                        {
                            s[i] = tmp[pos];
                            pos++;
                        }
                    }
                    end++;
                    break;
                }
                end++;
            }
        }
        start--;
    }
    for (int i = 0; i < n; i++)
    {
        cout << s[i];
    }
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