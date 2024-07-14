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

void DO(vector<int> &positions, vector<int> &healths, string direction)
{
    int n = positions.size();
    vector<pair<pair<int, int>, char>> v(n);
    for (int i = 0; i < n; i++)
    {
        v[i] = {{positions[i], healths[i]}, direction[i]};
    }
    sort(v.begin(), v.end());
    bool checkDiff = true;
    while (checkDiff == true)
    {
        for (int i = 0; i < n; i++)
        {
            if (v[i].second == 'R' && v[i + 1].second == 'L')
            {
                checkDiff = true;
                int mid = (v[i].first.first + v[i + 1].first.first);
                int posChange = max(v[i].first.first - mid, v[i + 1].first.first - mid);
                if (v[i].first.second < v[i + 1].first.second)
                {
                    v.erase(v.begin() + i);
                    n--;
                    v[i + 1].first.second--;
                }
                else if (v[i].first.second == v[i + 1].first.second)
                {
                    v.erase(v.begin() + i);
                    v.erase(v.begin() + i);
                    n -= 2;
                }
                else
                {
                    v.erase(v.begin() + (i + 1));
                    n--;
                    v[i].first.second--;
                }
                for (int j = 0; j < n; j++)
                {
                    if (v[i].second == 'L')
                    {
                        v[i].first.first -= posChange;
                    }
                    else
                        v[i].first.first += posChange;
                }
                break;
            }
            else
                checkDiff = false;
            // cout << v[i].first.first << " " << v[i].first.second << " " << v[i].second << endl;
        }
    }
    for (int i = 0; i < n; i++)
        cout << v[i].first.second << " ";
}

void solve()
{
    int n;
    cin >> n;
    vi po(n), he(n);
    string di;
    FOR(i, n)
    cin >> po[i];
    FOR(i, n)
    cin >> he[i];
    cin >> di;
    DO(po, he, di);
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