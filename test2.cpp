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

bool ascDistrict(int n)
{
    int last = 9;
    while (n > 0)
    {
        int tmp = n % 10;
        if (tmp > last)
            return false;
        last = tmp;
        n /= 10;
    }
    return true;
}

void solve()
{
    int n;
    cin >> n;
    if (ascDistrict(n) == false)
        cout << "-1" << endl;
    else
    {
        int largest = n;
        while (!ascDistrict(largest))
            largest--;
        int cnt = 0;
        for (int i = 1; i <= largest; i++)
        {
            if (ascDistrict(i) == true)
                cnt++;
        }
        cout << cnt << endl;
    }
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
