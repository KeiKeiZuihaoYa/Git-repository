#include <iostream>
#include <iomanip>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<string, double> P;

bool cmp(P a, P b)
{
    return a.first < b.first;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    map<string, int> mp;
    int tot = 0;
    string name;

    while (getline(cin, name))
    {
        mp[name]++;
        tot++;
    }

    cout << fixed << setprecision(4);

    vector<P> v;
    for (map<string, int>::iterator it = mp.begin(); it != mp.end(); it++)
    {
        P i = *it;
        v.push_back({i.first, (double)i.second / tot * 100});
    }

    sort(v.begin(), v.end(), cmp);

    for (vector<P>::iterator it = v.begin(); it != v.end(); it++)
    {
        P i = *it;
        cout << i.first << " " << i.second << endl;
    }
    return 0;
}