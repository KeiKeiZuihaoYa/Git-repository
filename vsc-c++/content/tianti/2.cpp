#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> P;
const int inf = 0x3f3f3f3f << 1;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    double a, b, c;
    cin >> a >> b >> c;
    double res = 0.2 * a + b * 0.3 + c * 0.5;
    cout << res;

    return 0;
}