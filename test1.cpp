#include <bits/stdc++.h>
#define ll long long
#define db double
#define fl float
#define FOR(i, n) for (int i = 0; i < (n); i++)
#define REP(i, a, b) for (int i = (a); i <= (b); i++)
#define vi vector<int>
#define SZ(x) (x).size()
#define ALL(x) (x).begin(), (x).end()
#define pb(x) (x).push_back
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#pragma GCC optimize("03")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2")

using namespace std;

bool bs(int a[], int n, int x, int l, int r)
{
    if (l > r)
        return false;
    int mid = (l + r) / 2;
    if (a[mid] == x)
        return true;
    if (a[mid] < mid)
        return bs(a, n, x, mid + 1, r);
    else
        return bs(a, n, x, l, mid - 1);
}

void solve()
{
    int n;
    cin >> n;
    int a[n];
    FOR(i, n)
    cin >> a[i];
    int x;
    cin >> x;
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