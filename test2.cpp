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

class Robot
{
private:
    int pos;
    int hel;
    char direc;

public:
    Robot();
    Robot(int pos, int hel, char direc);
    int getPos() { return this->pos; }
    int getHel() { return this->hel; }
    char getDirec() { return this->direc; }
    void display();
};

Robot::Robot() {}
Robot::Robot(int pos, int hel, char direc) : pos(pos), hel(hel), direc(direc) {}
void Robot::display()
{
    cout << "Position: " << this->pos << ", Helth: " << this->hel << ", Direction: " << this->direc << endl;
}

void solve()
{
    int n;
    cin >> n;
    Robot rb[n];
    for (int i = 0; i < n; i++)
    {
        int x, y;
        char z;
        cin >> x >> y >> z;
        rb[i] = Robot(x, y, z);
    }
    for (int i = 0; i < n; i++)
    {
        rb[i].display();
    }
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