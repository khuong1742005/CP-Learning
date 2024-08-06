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

int A[200005];
ll ST[840008];
const int op = 1e9 + 10;
int n, q;

int check(int n)
{
    int k = 0;
    while (n != 0)
    {
        n = n / 3;
        k++;
    }
    return k;
}

void update(int id, int l, int r, int i, int v)
{
    if (i < l || r < i)
    {

        return;
    }
    if (l == r)
    {

        ST[id] = v;
        return;
    }

    int mid = (l + r) / 2;
    update(id * 2, l, mid, i, v);
    update(id * 2 + 1, mid + 1, r, i, v);

    ST[id] = ST[id * 2] + ST[id * 2 + 1];
}

ll get(int id, int l, int r, int u, int v)
{
    if (v < l || r < u)
    {

        return 0;
    }
    if (u <= l && r <= v)
    {

        return ST[id];
    }
    int mid = (l + r) / 2;

    return get(id * 2, l, mid, u, v) + get(id * 2 + 1, mid + 1, r, u, v);
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
        int l, r;
        cin >> l >> r;
        cout << get(1, 1, 200000, l + 1, r) + check(l) * 2 << endl;
    }

    return 0;
}
