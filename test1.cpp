#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5;
int a[maxn];
int it[maxn * 4];
int n, q;

void Update(int pos, int val, int node = 1, int l = 1, int r = n)
{
    if (pos < l || r < pos)
        return;
    if (l == r)
        return a[pos] = it[node] = val, void();
    int m = (l + r) / 2;
    Update(pos, val, node * 2, l, m);
    Update(pos, val, node * 2 + 1, m + 1, r);
    it[node] = it[node * 2] + it[node * 2 + 1];
}

int Get(int a, int b, int node = 1, int l = 1, int r = n)
{
    if (b < l || r < a)
        return 0;
    if (a <= l && r <= b)
        return it[node];
    int m = (l + r) / 2;
    return Get(a, b, node * 2, l, m) + Get(a, b, node * 2 + 1, m + 1, r);
}

void solve()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        Update(i, a[i]);
    }
    while (q--)
    {
        int type, a, b, k, u;
        cin >> type;
        if (type == 1)
        {
            cin >> k >> u;
            Update(k, u);
        }
        else
        {
            cin >> a >> b;
            cout << Get(a, b) << '\n';
        }
    }
}

int main()
{
    solve();
}