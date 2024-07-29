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

const int N = 1e6;

using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> Person(n, 0), Task(m);
    FOR(i, m)
    cin >> Task[i];
    int freq[N] = {0};
    FOR(i, m)
    {
        freq[Task[i]]++;
    }
    int Max = 0;
    int aim = 0;
    for (int i = 0; i < m; i++)
    {
        if (freq[Task[i]] > Max)
        {
            cout << "checked";
            Max = freq[Task[i]];
        }
        //     if (freq[i] != 0)
        //     {
        //         Person[i] = freq[i];
        //     }
    }
    cout << Max;
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