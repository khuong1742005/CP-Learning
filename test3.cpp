#include <bits/stdc++.h>
using namespace std;

#define int long long

const int maxn = 200005;
int a[maxn];
int t[maxn * 4];

void build(int id, int l, int r)
{
    if (l == r)
    {
        t[id] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    t[id] = t[id * 2] + t[id * 2 + 1];
}
int get(int id, int l, int r, int u, int v)
{
    if (r < u || v < l)
        return 0;
    if (u <= l && r <= v)
    {
        return t[id];
    }
    int mid = (l + r) / 2;
    return get(id * 2, l, mid, u, v) + get(id * 2 + 1, mid + 1, r, u, v);
}
void update(int id, int l, int r, int pos, int val)
{
    if (pos < l || pos > r)
        return;
    if (l == r)
    {
        a[pos] = val;
        t[id] = val;
        return;
    }
    int mid = (l + r) / 2;
    update(id * 2, l, mid, pos, val);
    update(id * 2 + 1, mid + 1, r, pos, val);
    t[id] = t[id * 2] + t[id * 2 + 1];
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        update(1, 1, n, i, a[i]);
    }

    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int k, u;
            cin >> k >> u;
            update(1, 1, n, k, u);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout << get(1, 1, n, l, r) << endl;
        }
    }
    return 0;
}