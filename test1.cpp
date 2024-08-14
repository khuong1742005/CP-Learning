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
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#pragma GCC optimize("03")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2")

#define int long long
using namespace std;

void solve()
{
    vector<int> stones;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        stones.push_back(x);
    }
    sort(stones.begin(), stones.end());
    int pos = 0;
    vector<int> st;
    int sum = 0;
    while (pos < n)
    {
        sum += stones[pos];
        if (sum % 3 == 0)
        {
            st.push_back(stones[pos]);
            sum -= stones[pos];
        }
        pos++;
    }
    if (st.size() == 0)
    {
        yes
    }
    else
    {
        int sz = st.size();
        for (int i = 0; i < st.size(); i++)
        {
            sum += st[i];
            if (sum % 3 != 0)
            {
                sz--;
            }
            else
            {
                sum -= st[i];
            }
        }
        if (sz == 0)
            no else if (sz == st.size())
            {
                int tmp = n - st.size();
                if (tmp % 2 == 0)
                    no else yes
            }
        else
        {
            int tmp = st.size() - sz;
            if (tmp % 2 == 0)
                yes else no
        }
    }
    for (auto x : st)
        cout << x << " ";
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
