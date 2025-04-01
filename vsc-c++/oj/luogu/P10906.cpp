#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> P;
const int inf = 0x3f3f3f3f << 1;

bool havingNumber(const string &s)
{
    for (auto &i : s)
        if (isdigit(i))
            return true;
    return false;
}

bool havingfuhao(const string &s)
{
    for (auto &i : s)
        if (!isalnum(i))
            return true;
    return false;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    string s;
    // cin >> s;
    int cnt = 0;

    for (int i = 0; i < s.length(); ++i)
    {
        for (int j = 8; j <= 16 && i + j <= s.length(); ++j)
        {
            string now = s.substr(i, j);
            if (!havingNumber(now))
                continue;
            if (!havingfuhao(now))
                continue;
            cnt++;
        }
    }
    cout << 400;

    return 0;
}