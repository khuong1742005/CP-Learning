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

// vector<int>
void DO(vector<int> &positions, vector<int> &healths, string directions)
{
    int n = positions.size();
    vector<int> ans;

    vector<vector<int>> v(n, vector<int>(3));
    for (int i = 0; i < n; i++)
    {
        v[i][0] = positions[i];
        v[i][1] = healths[i];
        if (directions[i] == 'R')
            v[i][2] = 1;
        else
            v[i][2] = -1;
    }
    sort(v.begin(), v.end());

    stack<pair<pair<int, int>, int>> cur;
    vector<pair<int, int>> pos;
    for (int i = 0; i < n; i++)
    {
        if (v[i][2] == 1)
            cur.push({{v[i][0], v[i][1]}, v[i][2]});
        else
        {
            if (!cur.empty())
            {
                if (v[i][1] < cur.top().first.second)
                {
                    cur.top().first.second--;
                    continue;
                }
                else if (v[i][1] > cur.top().first.second)
                {
                    while (!cur.empty())
                    {
                        if (v[i][1] < cur.top().first.second)
                        {
                            cur.top().first.second--;
                            break;
                        }
                        else if (v[i][1] > cur.top().first.second)
                        {
                            cur.pop();
                            v[i][1]--;
                        }
                        else if (v[i][1] == cur.top().first.second)
                        {
                            cur.pop();
                            break;
                        }
                        if (cur.empty())
                        {
                            pos.push_back({v[i][0], v[i][1]});
                            break;
                        }
                    }
                }
                else if (v[i][1] == cur.top().first.second)
                {
                    cur.pop();
                    continue;
                }
            }
            else
            {
                pos.push_back({v[i][0], v[i][1]});
                continue;
            }
        }
    }
    while (!cur.empty())
    {
        pos.push_back({cur.top().first.first, cur.top().first.second});
        cur.pop();
    }
    // sort(pos.begin(), pos.end());
    for (int i = 0; i < pos.size(); i++)
    {
        // ans.push_back(pos[i].second);
        cout << pos[i].first << ' ' << pos[i].second << endl;
    }
    // return ans;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> positions(n), healths(n);
    string directions;
    FOR(i, n)
    cin >> positions[i];
    FOR(i, n)
    cin >> healths[i];
    cin >> directions;
    // vector<int> v = DO(positions, healths, directions);
    // for (int i = 0; i < v.size(); i++)
    // {
    //     cout << v[i] << ' ';
    // }
    DO(positions, healths, directions);
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