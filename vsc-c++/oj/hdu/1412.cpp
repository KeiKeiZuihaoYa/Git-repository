#include <bits/stdc++.h>
using namespace std;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    while (cin >> n >> m)
    {
        string line;
        set<int> a;
        for (int i = 0; i < 2; i++)
        {
            for (int j = (i == 0 ? n : m), tmp; j; j--)
            {
                cin >> tmp;
                a.insert(tmp);
            }
        }
        for (auto i : a)
            cout << i << ' ';
        cout << '\n';
    }
    return 0;
}