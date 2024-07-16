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

int gt(int n)
{
    if (n == 1)
        return 1;
    return n * gt(n - 1);
}
int Do(vector<int> &nums, int k)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int ans = gt(n);
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (abs(nums[j] - nums[i]) == k)
                cnt++;
        }
    }
    return ans - cnt;
}

void solve()
{
    int n;
    cin >> n;
    vi v(n);
    FOR(i, n)
    cin >> v[i];
    int k;
    cin >> k;
    cout << Do(v, k) << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int t; cin >> t;
    int t = 1;
    while (t--)
    {
        solve();
    }

    return 0;
}