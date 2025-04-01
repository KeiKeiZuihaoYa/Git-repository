#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> P;
const int inf = 0x3f3f3f3f << 1;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int k;
    string s;
    char a, b;
    cin >> k >> s >> a >> b;

    long long ans = 0, cnt = 0;

    for (int i = 0, j = k - 1; j < s.length(); ++i, ++j)
    {
        if (s[i] == a)
            cnt++;
        if (s[j] == b)
            ans += cnt;
    }
    cout << ans;

    return 0;
}