#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> fama(6);

int wei(int x)
{
    int res;
    switch (x)
    {
    case 0:
        res = 1;
        break;
    case 1:
        res = 2;
        break;
    case 2:
        res = 3;
        break;
    case 3:
        res = 5;
        break;
    case 4:
        res = 10;
        break;
    case 5:
        res = 20;
        break;

    default:
        break;
    }
    return res;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    for (int i = 0; i < 6; i++)
        cin >> fama[i];

    set<int> s;
    for (int i = 0; i < 6; i++)
    {
        set<int> ns;      // now——step——Set
        vector<int> tmpv; // 当前规格的砝码， 所能有的重量组合
        for (int k = 1; k <= fama[i]; k++)
            ns.insert(wei(i) * k);
        for (auto &j : ns)
            tmpv.push_back(j);

        for (auto &j : tmpv)
            for (auto &k : s)
                ns.insert(j + k);
        s.insert(ns.begin(), ns.end());
    }

    cout << "Total=" << s.size();

    return 0;
}