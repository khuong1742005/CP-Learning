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
    int n, m;
    cin >> n >> m;
    vector<int> nums1(n);
    vector<int> nums2(m);
    FOR(i, n)
    cin >> nums1[i];
    FOR(i, m)
    cin >> nums2[i];
    int ans1 = 0, ans2 = 0;
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    ans1 = nums1[0];
    ans2 = nums2[0];
    vector<int> ans;
    if (ans1 > ans2)
        ans.push_back(ans2 * 10 + ans1);
    else if (ans2 > ans1)
        ans.push_back(ans1 * 10 + ans2);
    else
    {
        ans.push_back(ans1);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (nums1[i] == nums2[j])
                ans.push_back(nums1[i]);
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans[0];
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