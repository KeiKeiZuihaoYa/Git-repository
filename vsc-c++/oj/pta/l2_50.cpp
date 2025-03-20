#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

string getHead(const string &line)
{
    string now, headstring;
    istringstream is(line);
    while (is >> now)
    {
        headstring += now[0];
    }
    return headstring;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n;
    cin.ignore();
    unordered_map<string, multiset<string>> mp;
    for (int i = 1; i <= n; i++)
    {
        string line, now, headstring;
        getline(cin, line);
        headstring = getHead(line);
        mp[headstring].insert(line);
    }
    cin >> m;
    cin.ignore();
    for (int i = 1; i <= m; i++)
    {
        string line, now, headstring;
        getline(cin, line);
        headstring = getHead(line);
        if (!mp.count(headstring))
        {
            cout << line << '\n';
            continue;
        }
        multiset<string> &s = mp[headstring];
        auto j = s.begin();
        while (j != s.end())
        {
            cout << *j;
            j++;
            cout << "|\n"[j == s.end()];
        }
    }

    return 0;
}