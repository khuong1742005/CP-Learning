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

vector<ii> adj[N];
int dis[N];
vector<vector<int>> triangle;

void getInput()
{
    // int side = 0;
    // for (int i = 1; i < triangle.size(); i++)
    // {
    //     side += i * 2;
    // }
    for (int i = 0; i < triangle.size() - 1; i++)
    {
        for (int j = 0; j < triangle[i].size(); j++)
        {
            int u = triangle[i][j];
            int v1 = triangle[i + 1][j];
            int v2 = triangle[i + 1][j + 1];
            adj[u].push_back({v1, abs(u - v1)});
            adj[u].push_back({v2, abs(u - v2)});
        }
    }
}

void Dijkstra(int root)
{
    priority_queue<ii, vector<ii>, greater<ii>> pque;
    fill(dis, dis + N, INF);
    dis[root] = 0;
    pque.push({0, root});
    while (pque.size())
    {
        auto [len, node] = pque.top();
        pque.pop();
        for (auto [child, weight] : adj[node])
            if (len + weight < dis[child])
                dis[child] = len + weight,
                pque.push({dis[child], child});
    }
}

void solve()
{
    Dijkstra(triangle[0][0]);
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
        getInput();
        solve();
    }

    return 0;
}
