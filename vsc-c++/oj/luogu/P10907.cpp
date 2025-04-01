#include <bits/stdc++.h>
using namespace std;
typedef pair<double, double> P;

struct node
{
    P a, b;
};

bool isIntPoint(P &point)
{
    if (point.first - (int)point.first)
        return false;
    if (point.second - (int)point.second)
        return false;
    return true;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<node> v(n);
    for (auto &i : v)
    {
        cin >> i.a.first >> i.a.second >> i.b.first >> i.b.second;
        if (i.a.first > i.b.first)
            swap(i.a, i.b);
    }

    set<P> s;

    return 0;
}