#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> P;
const int inf = 0x3f3f3f3f << 1;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        if (s.length() <= 10)
            cout << s << '\n';
        else
        {
            cout << s[0] << s.length() - 2 << s[s.length() - 1] << '\n';
        }
    }

    return 0;
}