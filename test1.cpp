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

unordered_map<int, int> mp;

int Do(int n)
{
    if (n == 1)
        return 0;
    if (mp.find(n) != mp.end())
        return mp[n];
    int step;
    if (n % 2 == 0)
        step = 1 + Do(n / 2);
    else
        step = 1 + Do(n * 3 + 1);
    mp[n] = step;
    return step;
}

void solve()
{
    int n;
    cin >> n;
    cout << Do(n) << '\n';
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