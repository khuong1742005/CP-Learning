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
    int n;
    cin >> n;
    vector<string> s1(n), s2(n);
    for (int i = 0; i < n; i++)
        cin >> s1[i];
    for (int i = 0; i < n; i++)
        cin >> s2[i];
    vector<string> cur1, cur2;
    int cnt = 0;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (s1[i] == s2[i] && cnt == 0)
        {
            ans.push_back(1);
        }
        else
        {
            auto it1 = find(cur1.begin(), cur1.end(), s2[i]);
            auto it2 = find(cur2.begin(), cur2.end(), s1[i]);
            if (it1 != cur1.end() && it2 != cur2.end())
            {
                // cout << s1[i] << " " << s2[i] << endl;
                ans.push_back(cnt + 1);
                cnt = 0;
                cur1.clear();
                cur2.clear();
            }
            else
            {
                cur1.push_back(s1[i]);
                cur2.push_back(s2[i]);
                cnt++;
            }
        }
    }
    for (auto x : ans)
    {
        cout << x << " ";
    }
    cout << '\n';
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
