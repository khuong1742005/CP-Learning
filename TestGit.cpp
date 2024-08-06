#include <iostream>
using namespace std;
#define ll long long
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

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 1; i <= 200000; ++i)
    {
        update(1, 1, 200000, i, check(i));
    }

    int t;
    cin >> t;
    while (t--)
    {
        int l, r;
        cin >> l >> r;
        cout << get(1, 1, 200000, l + 1, r) + check(l) * 2 << endl;
    }
}