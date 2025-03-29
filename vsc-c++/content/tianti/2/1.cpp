#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> P;
const int inf = 0x3f3f3f3f << 1;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int y, m;
    cin >> y >> m;
    if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
        cout << 31;
    else if (m != 2)
        cout << 30;
    else
    {
        if ((y % 100 != 0 && y % 4 == 0) || y % 400 == 0)
            cout << 29;
        else
            cout << 28;
    }

    return 0;
}