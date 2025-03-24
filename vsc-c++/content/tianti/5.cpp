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
    ll sum = 0;
    string maxName;
    ll maxTot = 0;
    for (int i = 1; i <= n; i++)
    {
        string name, xveshengganbu, xibu;
        int pingshi, banji, lunwen;
        cin >> name >> pingshi >> banji >> xveshengganbu >> xibu >> lunwen;

        ll nowCnt = 0;
        if (pingshi > 80 && lunwen >= 1)
            nowCnt += 8000;
        if (pingshi > 85 && banji > 80)
            nowCnt += 4000;
        if (pingshi > 90)
            nowCnt += 2000;
        if (pingshi > 85 && xibu == "Y")
            nowCnt += 1000;
        if (banji > 80 && xveshengganbu == "Y")
            nowCnt += 850;

        sum += nowCnt;
        if (maxTot < nowCnt)
            maxTot = nowCnt, maxName = name;
    }

    cout << maxName << '\n'
         << maxTot << '\n'
         << sum;

    return 0;
}