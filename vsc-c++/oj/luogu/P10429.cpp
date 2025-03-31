#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> P;
const int inf = 0x3f3f3f3f << 1;

vector<ll> sum;
vector<set<ll>> vs;
vector<set<ll>> vb;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vs.resize(n);
    vb.resize(n);
    vector<ll> v(n);

    for (auto &i : v)
        cin >> i;

    set<ll> nows;
    for (int i = n - 1; i >= 0; --i)
    {
        vector<ll> tmp;
        tmp.push_back(v[i]);

        for (auto &j : nows)
            tmp.push_back(j + v[i]);

        for (auto &j : tmp)
            nows.insert(j);
        vs[i].insert(nows.begin(), nows.end());
    }

    nows.clear();
    for (int i = 0; i < n; i++)
    {
        vector<ll> tmp;
        tmp.push_back(v[i]);

        for (auto &j : nows)
            tmp.push_back(j + v[i]);
        for (auto &j : tmp)
            nows.insert(j);
    }

    return 0;
}
