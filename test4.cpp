#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 1e5 + 5;

int n, q, a[N];
vector<pair<int, int>> query[3];

void GetInput()
{
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    query[1].emplace_back();
    query[2].emplace_back();
    for (int i = 1, f; i <= q; ++i)
    {
        cin >> f;
        query[f].emplace_back();
        cin >> query[f].back().first >> query[f].back().second;
    }
}

void CompressWithOrder()
{
    vector<pair<int, pair<int, int>>> hub;
    for (int i = 1; i <= n; ++i)
        hub.push_back({a[i], {1, i}});
    for (int i = 1; i < query[1].size(); ++i)
        hub.push_back({query[1][i].first, {2, 2 * i}}),
            hub.push_back({query[1][i].second, {2, 2 * i + 1}});
    for (int i = 1; i < query[2].size(); ++i)
        hub.push_back({query[2][i].first, {3, 2 * i}}),
            hub.push_back({query[2][i].second, {3, 2 * i + 1}});
    sort(hub.begin(), hub.end());

    for (int i = 0, cur = 0; i < hub.size(); ++i)
    {
        cur += i == 0 || hub[i].first != hub[i - 1].first;
        auto [val, loc] = hub[i];
        auto [arr, id] = loc;
        if (arr == 1)
            a[id] = cur;
        else if (arr == 3)
        {
            if (id % 2 == 0)
                query[arr - 1][id / 2].first = cur;
            else
                query[arr - 1][id / 2].second = cur;
        }
        else
        {
            if (id % 2)
                query[arr - 1][id / 2].second = cur;
        }
    }
}

void Log()
{
    for (int i = 1; i <= n; ++i)
        cout << a[i] << ' ';
    cout << '\n';
    for (int i = 1; i < query[1].size(); ++i)
        cout << '<' << query[1][i].first << " - " << query[1][i].second << '>';
    cout << '\n';
    for (int i = 1; i < query[2].size(); ++i)
        cout << '<' << query[2][i].first << " - " << query[2][i].second << '>';
}

signed main()
{
    GetInput();
    CompressWithOrder();
    Log();
}