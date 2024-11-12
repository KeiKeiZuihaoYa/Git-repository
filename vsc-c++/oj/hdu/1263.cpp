#include <bits/stdc++.h>
using namespace std;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int _, n, c;
    string a, b;
    cin >> _;
    while (_--)
    {
        map<string, map<string, int>> mp;
        cin >> n;
        while (n--)
        {
            cin >> a >> b >> c;
            mp[b][a] += c;
        }

        for (auto &[cd, ump] : mp)
        {
            cout << cd << "\n";
            for (auto i : ump)
                cout << "   |----" << i.first << "(" << i.second << ")\n";
        }

        if (_)
            cout << "\n";
    }

    return 0;
}