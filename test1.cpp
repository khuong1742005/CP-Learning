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
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#pragma GCC optimize("03")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2")

#define int long long
#define ii pair<int, int>
const int N = 1e5 + 5;
const int INF = 2e18 + 5;
using namespace std;

int n, m;
vector<ii> adj[N];
vector<int> ans;
int dis[N];

void GetInput()
{
    cin >> n >> m;
    int u, v, w;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
}
void DJK(int root)
{
    priority_queue<ii, vector<ii>, greater<ii>> pque;
    fill(dis, dis + N, INF);
    dis[root] = 0;
    pque.push({0, root});
    while (!pque.empty())
    {
        auto [len, node] = pque.top();
        pque.pop();
        for (auto [child, weight] : adj[node])
        {
            if (len + weight < dis[child])
            {
                dis[child] = len + weight;
                pque.push({dis[child], child});
            }
        }
    }
}
void solve()
{
    DJK(1);
    for (int node : ans)
    {
        cout << node << ' ';
    }
    cout << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int t;
    // cin >> t;
    int t = 1;
    while (t--)
    {
        GetInput();
        solve();
    }

    return 0;
}
